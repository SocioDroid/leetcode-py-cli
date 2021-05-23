from src.config import *

cookies = getCookies()
data = getGraphqlData()
baseurl = getBaseURL()
solvedQuestions = getSolvedQuestions()
availableSubmissions = getSubmissionDirectoryContents()
submissionDirectory = getSubmissionDirectory()
submissionjson = submissionDirectory+"submission.json"
codeDirectory = submissionDirectory+"/code/"
language = getLanguages()
jsonfile = []
solvedSubmissions = {}
rateLimitedQuestions = {}