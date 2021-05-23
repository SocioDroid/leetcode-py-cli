from .config import *
import os
import pyfiglet

ascii_banner = pyfiglet.figlet_format("Leetcode cli")
print(ascii_banner)

removeQuotes()

cookies = getCookies()
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