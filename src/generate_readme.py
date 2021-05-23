from os import listdir
from os.path import isfile, join
from collections import OrderedDict
from .config import getBaseURL, getLanguages, getSubmissionDirectory
import json
def generateReadme():
    languages = getLanguages()
    languages = {v: k for k, v in languages.items()}

    onlyfiles = [f for f in listdir(getSubmissionDirectory()) if isfile(join(".", getSubmissionDirectory()+f))]
    solvedProblems = {}
    submissionjson = getSubmissionDirectory()+"submission.json"
    jsonfile = json.load(open(submissionjson))
    jsonfile = list({v['id']:v for v in jsonfile}.values())
    solvedProblems = sorted(jsonfile, key=lambda k: k['id'])
    readme='''
# Leetcode Solutions
My accepted leetcode solutions

|NO|Title|Runtime|Memory|Timestamp|Solution|
|---|-----|--------|-------|--------|--------|
'''
    for problem in solvedProblems:
        readme+="|{}|[{}]({})|{}|{}|{}|[{}]({})|\n".format(problem["id"],problem["title"].title(),"https://leetcode.com/problems/"+problem["url"],problem["runtime"],problem["memory"],problem["timestamp"],problem["language"],problem["filename"])

    f = open(getSubmissionDirectory()+"README.md", 'w')
    f.seek(0)
    f.write(readme)
    f.truncate()
    f.close()