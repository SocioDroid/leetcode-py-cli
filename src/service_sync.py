import os
import requests
import json
import re
from .config import *
from dotenv import load_dotenv
from datetime import datetime
import requests
from src.init import *


def getSubmissions(title):
    data["variables"]["questionSlug"] = title
    resp = requests.post(baseurl+"/graphql",
                         cookies=cookies, json=data, timeout=10)
    resp = json.loads(resp.content.decode('utf-8'))
    for submission in resp["data"]["submissionList"]["submissions"]:
            if submission["statusDisplay"] == "Accepted":
                return submission
    

def getSubmissionCode(submissionURL):
    resp = requests.get(baseurl+submissionURL, cookies=cookies, timeout=10)
    code = re.search("submissionCode:.*", resp.text).group(0)
    return eval(code[16:-1])


def writeSubmission(id, submission):
    # get submissions
    code = getSubmissionCode(submission['url'])

    # Write into file
    title = solvedQuestions[id]
    lang = submission["lang"]
    filename = "{}.{}.{}".format(id, title, language[lang])

    fd = open(codeDirectory+filename, "w+")
    fd.write(code)
    # write into file

    jsonfile.append({
        "id": id,
        "title": " ".join(title.split("-")),
        "url": title,
        "filename": filename,
        "timestamp": datetime.utcfromtimestamp(int(submission["timestamp"])).strftime('%d-%m-%Y %H:%M'),
        "memory": submission["memory"],
        "runtime": submission["runtime"],
        "language": lang
    })
    # Write into json

    print("Submission stored at: " + submissionDirectory+filename)
    return


def downloadSubmission(id):
    solvedQuestions = getSolvedQuestions()
    if id in solvedQuestions:
        submission = getSubmissions(solvedQuestions[id])
        writeSubmission(id, submission)
        with open(submissionDirectory+'submission.json', 'w') as f:
            json.dump(jsonfile, f)
        return

    print("You haven't solved this question yet or have no accepted solutions.")