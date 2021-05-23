import os
from dotenv import load_dotenv
import requests
import json
load_dotenv()
def handleError(error):
    print(error)
    pass

def check():
    if os.environ['LEETCODE_CSRFTOKEN'] and os.environ['LEETCODE_SESSION']:
        return True
    return False

def getCookies():
    if check():
        cookies = {
            "csrftoken": os.getenv("LEETCODE_CSRFTOKEN"), 
            "LEETCODE_SESSION": os.getenv("LEETCODE_SESSION")
            }
        return cookies
    else:
        handleError("Please fill the credentials in .env directory !")

def getSubmissionDirectory():
    directory = os.getenv("SUBMISSION_DIRECTORY")
    if not os.path.exists(directory):
        os.makedirs(directory)
    if not os.path.isfile(directory+"submission.json"):
        open(directory+"submission.json", 'w').close()
    return directory

def getSubmissionDirectoryContents():
    content = os.listdir(getSubmissionDirectory())
    return [x.split('.')[0] for x in content]    
    
def getGraphqlData():
    data = {
    "operationName": "Submissions", 
    "query": "query Submissions($offset: Int!, $limit: Int!, $lastKey: String, $questionSlug: String!) {\n  submissionList(offset: $offset, limit: $limit, lastKey: $lastKey, questionSlug: $questionSlug) {\n    lastKey\n    hasNext\n    submissions {\n      id\n      statusDisplay\n      lang\n      runtime\n      timestamp\n      url\n      isPending\n      memory\n      __typename\n    }\n    __typename\n  }\n}\n", 
    "variables": {
        "lastKey": None, 
        "limit": 20, 
        "offset": 0, 
        "questionSlug": ""
        }
    }
    return data

def getBaseURL():
    return "https://leetcode.com"
    
def getLanguages():
    languages = {
        "cpp":"cpp",
        "java":"java",
        "python":"py",
        "python3":"py",
        "c":"c",
        "csharp":"cs",
        "javascript":"js",
        "ruby":"rb",
        "swift":"swift",
        "golang":"go",
        "scala":"sc",
        "kotlin":"kt",
        "rust":"rs",
        "php":"php",
        "typescript":"ts",
        "racket":"rkt"
    }
    return languages

def getSolvedQuestions():
    solvedQuestions = {}
    resp = requests.get(getBaseURL()+"/api/problems/all/",
                        cookies=getCookies(), timeout=10)
    f = open("out.txt", "w+")
    f.write(resp.text)
    f.close()
    
    question_list = json.loads(resp.content.decode('utf-8'))
    for question in question_list['stat_status_pairs']:
        if question["status"] == "ac":
            solvedQuestions.update({
                question['stat']["frontend_question_id"]: question['stat']["question__title_slug"]
            })
    return solvedQuestions


# def init():
    # print(cookies)
    # data = getGraphqlData()
    # baseurl = getBaseURL()
    # solvedQuestions = getSolvedQuestions()
    # availableSubmissions = getSubmissionDirectoryContents()
    # submissionDirectory = getSubmissionDirectory()
    # submissionjson = submissionDirectory+"submission.json"
    # language = getLanguages()
    # jsonfile = []
    # solvedSubmissions = {}
    # solvedQuestions = {}
    # rateLimitedQuestions = {}