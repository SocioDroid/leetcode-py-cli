import os
import requests
import json
import re
from .config import *
from datetime import datetime
import requests
import src.init as init


def getSubmissions(title):
    init.data["variables"]["questionSlug"] = title
    resp = requests.post(init.baseurl+"/graphql",
                         cookies=init.cookies, json=init.data, timeout=10)
    resp = json.loads(resp.content.decode('utf-8'))
    for submission in resp["data"]["submissionList"]["submissions"]:
            if submission["statusDisplay"] == "Accepted":
                return submission
    

def getSubmissionCode(submissionURL):
    resp = requests.get(init.baseurl+submissionURL, cookies=init.cookies, timeout=10)
    code = re.search("submissionCode:.*", resp.text).group(0)
    return eval(code[16:-1])


def writeSubmission(id, submission):
    # get submissions
    code = getSubmissionCode(submission['url'])

    # Write into file
    title = init.solvedQuestions[id]
    lang = submission["lang"]
    filename = "{}.{}.{}".format(id, title, init.language[lang])

    fd = open(init.codeDirectory+filename, "w+")
    fd.write(code)
    # write into file

    init.jsonfile.append({
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

    print("Submission stored at: " + init.submissionDirectory+filename)
    return


def downloadSubmission(id):
    init.solvedQuestions = getSolvedQuestions()
    # print(solvedQuestions, type(id), id)
    if id in init.solvedQuestions:
        submission = getSubmissions(init.solvedQuestions[id])
        writeSubmission(id, submission)
        with open(init.submissionDirectory+'submission.json', 'w') as f:
            json.dump(init.jsonfile, f)
        return

    print("You haven't solved this question yet or have no accepted solutions.")