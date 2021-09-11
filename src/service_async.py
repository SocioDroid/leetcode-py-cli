import os
from sys import implementation
import requests
import json
import re
from .config import *
from dotenv import load_dotenv
from datetime import datetime
import requests
import asyncio
from concurrent.futures import ThreadPoolExecutor
import time
import src.init as init
from halo import Halo

rateLimitFlag = False


def get_submissions_async_request(session, id, title):
    data = init.data
    data["variables"]["questionSlug"] = title
    with session.post(init.baseurl+"/graphql", json=data) as response:
        resp = json.loads(response.content.decode('utf-8'))
        if response.status_code != 200:
            print("FAILURE::{0}".format(data))

        for submission in resp["data"]["submissionList"]["submissions"]:
            if submission["statusDisplay"] == "Accepted":
                init.solvedSubmissions[id] = submission


async def get_submissions_asynchronous():
    with ThreadPoolExecutor(max_workers=5) as executor:
        with requests.Session() as session:
            # Set any session parameters here before calling `fetch`
            requests.utils.add_dict_to_cookiejar(session.cookies, init.cookies)

            loop = asyncio.get_event_loop()
            tasks = [
                loop.run_in_executor(
                    executor,
                    get_submissions_async_request,
                    # Allows us to pass in multiple arguments to `fetch`
                    *(session, id, title)
                )
                for id, title in init.solvedQuestions.items()
            ]
            for response in await asyncio.gather(*tasks):
                pass


def get_submission_code_async_request(session, id, submission):

    if str(id) in init.availableSubmissions:
        return

    with session.get(init.baseurl+submission["url"]) as response:
        if response.status_code != 200:
            if response.status_code == 429:
                init.rateLimitedQuestions.update({
                    id: submission
                })
                return
            print("FAILURE::{0}".format(id))

        code = re.search("submissionCode:.*", response.text).group(0)
        # if not code:

        title = init.solvedQuestions[id]
        lang = submission["lang"]
        filename = "{}.{}.{}".format(id, title, init.language[lang])

        fd = open(init.codeDirectory+filename, "w+")
        fd.write(eval(code[16:-1]))
        # write into file

        init.jsonfile.append({
            "id": id,
            "title": " ".join(title.split("-")),
            "url": title,
            "filename": filename,
            "timestamp": datetime.utcfromtimestamp(int(submission["timestamp"])).strftime('%d-%m-%Y'),
            "memory": submission["memory"],
            "runtime": submission["runtime"],
            "language": lang
        })

        return


async def get_submission_code_asynchronous():
    with ThreadPoolExecutor(max_workers=5) as executor:
        with requests.Session() as session:
            # Set any session parameters here before calling `fetch`
            requests.utils.add_dict_to_cookiejar(session.cookies, init.cookies)

            loop = asyncio.get_event_loop()
            tasks = [
                loop.run_in_executor(
                    executor,
                    get_submission_code_async_request,
                    # Allows us to pass in multiple arguments to `fetch`
                    *(session, id, submission)
                )
                for id, submission in init.solvedSubmissions.items()
            ]
            for response in await asyncio.gather(*tasks):
                pass


def getallsubmissions():
    loop = asyncio.get_event_loop()
    future = asyncio.ensure_future(get_submission_code_asynchronous())
    loop.run_until_complete(future)

# @Halo(text='Loading Questions', spinner='dots')


def downloadAllSubmissions():
    global rateLimitFlag

    spinner = Halo(text='Gathering questions', spinner='dots')
    spinner.start()
    init.solvedQuestions = getSolvedQuestions()
    spinner.succeed("Questions loaded successfully")
    spinner = Halo(text='Loading submissions', spinner='dots')
    spinner.start()
    # global solvedSubmissions

    if len(init.solvedSubmissions) == 0:
        loop = asyncio.get_event_loop()
        future = asyncio.ensure_future(get_submissions_asynchronous())
        loop.run_until_complete(future)

    getallsubmissions()

    spinner.succeed("Submissions loaded successfully")
    spinner = Halo(text='Creating files', spinner='dots')
    spinner.start()

    while init.rateLimitedQuestions:
        init.solvedSubmissions = init.rateLimitedQuestions.copy()
        init.rateLimitedQuestions.clear()
        time.sleep(5)
        getallsubmissions()

    spinner.succeed("Files saved successfully at submissions/")

    spinner = Halo(text='Gathering details', spinner='dots')
    spinner.start()
    with open(init.submissionDirectory+'submission.json', 'w') as f:
        json.dump(init.jsonfile, f)
    spinner.succeed("Collected required details")
    spinner.stop()


class bcolors:
    HEADER = '\033[95m'
    OKBLUE = '\033[94m'
    OKCYAN = '\033[96m'
    OKGREEN = '\033[92m'
    WARNING = '\033[93m'
    FAIL = '\033[91m'
    ENDC = '\033[0m'
    BOLD = '\033[1m'
    UNDERLINE = '\033[4m'


def listStats():
    spinner = Halo(text='Gathering your statistics', spinner='dots')
    spinner.start()
    stats = getStats()
    init.stats = stats
    spinner.succeed("Stats loaded successfully")
    print(
        f"All: \t{stats['t_total']:6d} total, {stats['t_accepted']:6d} done, {stats['t_in_progress']:6d} in progress")
    print(
        f"{bcolors.OKGREEN}Easy: \t{stats['e_total']:6d} total, {stats['e_accepted']:6d} done, {stats['e_in_progress']:6d} in progress{bcolors.ENDC}")
    print(
        f"{bcolors.WARNING}Medium: {stats['m_total']:6d} total, {stats['m_accepted']:6d} done, {stats['m_in_progress']:6d} in progress{bcolors.ENDC}")
    print(
        f"{bcolors.FAIL}Hard: \t{stats['h_total']:6d} total, {stats['h_accepted']:6d} done, {stats['h_in_progress']:6d} in progress{bcolors.ENDC}")


def listSubmission():
    spinner = Halo(text='Gathering questions', spinner='dots')
    spinner.start()
    init.solvedQuestions = getSolvedQuestions()
    print(init.solvedQuestions)
    spinner.succeed("Questions loaded successfully")
    spinner = Halo(text='Loading submissions', spinner='dots')
    spinner.start()
    # global solvedSubmissions

    if len(init.solvedSubmissions) == 0:
        loop = asyncio.get_event_loop()
        future = asyncio.ensure_future(get_submissions_asynchronous())
        loop.run_until_complete(future)

    print(init.solvedSubmissions)
    init.jsonfile = []
    for id, submission in init.solvedSubmissions.items():
        title = init.solvedQuestions[id]
        lang = submission["lang"]
        # write into file
        filename = "{}.{}.{}".format(id, title, init.language[lang])

        init.jsonfile.append({
            "id": id,
            "title": " ".join(title.split("-")),
            "url": title,
            "filename": filename,
            "timestamp": datetime.utcfromtimestamp(int(submission["timestamp"])).strftime('%d-%m-%Y'),
            "memory": submission["memory"],
            "runtime": submission["runtime"],
            "language": lang
        })
    spinner.succeed("Submissions loaded successfully")
