from concurrent.futures import thread
from .config import *
import os
import pyfiglet
from threading import Thread
from dotenv import set_key, load_dotenv

ascii_banner = pyfiglet.figlet_format("LeetCode cli")
print(ascii_banner)

if not os.path.isfile('.env'):
    f = open('.env', 'w')
    string = '''
LEETCODE_CSRFTOKEN=
LEETCODE_SESSION=
SUBMISSION_DIRECTORY=submissions/
GITHUB_TOKEN=
GITHUB_REPO=

'''
    f.write(string)
    f.close()

load_dotenv()
if not check():
    session = input("Enter LEETCODE_SESSION : ")
    csrf = input("\nEnter csrftoken : ")
    set_key('.env', 'LEETCODE_SESSION', session)
    set_key('.env', 'LEETCODE_CSRFTOKEN', csrf)
    os.environ['LEETCODE_SESSION'] = session
    os.environ['LEETCODE_CSRFTOKEN'] = csrf


cookies = getCookies()
# print(cookies,'123414')
data = getGraphqlData()
baseurl = getBaseURL()
# solvedQuestions = getSolvedQuestions()
solvedQuestions = {}
availableSubmissions = getSubmissionDirectoryContents()
submissionDirectory = getSubmissionDirectory()
submissionjson = submissionDirectory+"submission.json"
codeDirectory = submissionDirectory+"/code/"
language = getLanguages()
jsonfile = []
solvedSubmissions = {}
rateLimitedQuestions = {}

if os.stat(submissionjson).st_size != 0:
    jsonfile = json.load(open(submissionjson))

