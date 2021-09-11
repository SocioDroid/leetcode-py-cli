import os
from dotenv import load_dotenv
import requests
import json
import itertools

load_dotenv()


def handleError(error):
    print(error)
    pass


def checkRepoURL():
    if "GITHUB_REPO" in os.environ and os.environ["GITHUB_REPO"] != "":
        return True
    return False


def getRepoURL():
    if checkRepoURL():
        return os.environ["GITHUB_REPO"]


def checkGithubToken():
    if os.environ["GITHUB_TOKEN"] and os.environ["GITHUB_TOKEN"] != "":
        return True
    return False


def getGithubToken():
    if checkGithubToken():
        return os.environ["GITHUB_TOKEN"]
    # else:
    #     # handle error
    #     handleError("Please fill the credentials. Run python3 leetcode-py-cli.py --github!")


def check():
    if (
        os.environ["LEETCODE_CSRFTOKEN"]
        and os.environ["LEETCODE_CSRFTOKEN"] != ""
        and os.environ["LEETCODE_SESSION"]
        and os.environ["LEETCODE_SESSION"] != ""
    ):
        return True
    return False


def getCookies():
    if check():
        cookies = {
            "csrftoken": os.getenv("LEETCODE_CSRFTOKEN"),
            "LEETCODE_SESSION": os.getenv("LEETCODE_SESSION"),
        }
        return cookies
    # else:
    #     handleError("Please login. Run python3 leetcode-py-cli.py --login!")


def getSubmissionDirectory():
    directory = os.getenv("SUBMISSION_DIRECTORY")
    if not os.path.exists(directory + "/code/"):
        os.makedirs(directory + "/code/")
    if not os.path.isfile(directory + "submission.json"):
        open(directory + "submission.json", "w").close()

    return directory


def getSubmissionDirectoryContents():
    content = os.listdir(getSubmissionDirectory() + "/code/")
    return [x.split(".")[0] for x in content]


def getGraphqlData():
    data = {
        "operationName": "Submissions",
        "query": "query Submissions($offset: Int!, $limit: Int!, $lastKey: String, $questionSlug: String!) {\n  submissionList(offset: $offset, limit: $limit, lastKey: $lastKey, questionSlug: $questionSlug) {\n    lastKey\n    hasNext\n    submissions {\n      id\n      statusDisplay\n      lang\n      runtime\n      timestamp\n      url\n      isPending\n      memory\n      __typename\n    }\n    __typename\n  }\n}\n",
        "variables": {"lastKey": None, "limit": 20, "offset": 0, "questionSlug": ""},
    }
    return data


def getBaseURL():
    return "https://leetcode.com"


def getLanguages():
    languages = {
        "cpp": "cpp",
        "java": "java",
        "python": "py",
        "python3": "py",
        "c": "c",
        "csharp": "cs",
        "javascript": "js",
        "ruby": "rb",
        "swift": "swift",
        "golang": "go",
        "scala": "sc",
        "kotlin": "kt",
        "rust": "rs",
        "php": "php",
        "typescript": "ts",
        "racket": "rkt",
    }
    return languages


def getSolvedQuestions():
    solvedQuestions = {}
    resp = requests.get(
        getBaseURL() + "/api/problems/all/", cookies=getCookies(), timeout=10
    )

    question_list = json.loads(resp.content.decode("utf-8"))
    for question in question_list["stat_status_pairs"]:
        if question["status"] == "ac":

            solvedQuestions.update(
                {
                    question["stat"]["frontend_question_id"]: question["stat"][
                        "question__title_slug"
                    ]
                }
            )

    return solvedQuestions


def getStats():
    resp = requests.get(
        getBaseURL() + "/api/problems/all/", cookies=getCookies(), timeout=10
    )
    question_list = json.loads(
        resp.content.decode("utf-8"))["stat_status_pairs"]
    levels_summary = {}
    translator = {
        1: "e",
        2: "m",
        3: "h",
        4: "super_hard",
        "ac": "accepted",
        None: "total",
        "notac": "in_progress"
    }
    status_set = set([x['status'] for x in question_list])
    level_set = set([x['difficulty']['level'] for x in question_list])
    for status in status_set:
        levels_summary[f't_{translator[status]}'] = len(
            [x for x in question_list if x['status'] == status])
    for level, status in itertools.product(level_set, status_set):
        levels_summary[f'{translator[level]}_{translator[status]}'] = len(
            [x for x in question_list if x['difficulty']['level'] == level and x['status'] == status])

    return levels_summary
