from src.config import *

cookies = getCookies()
data = getGraphqlData()
baseurl = getBaseURL()
solvedQuestions = getSolvedQuestions()
availableSubmissions = getSubmissionDirectoryContents()
submissionDirectory = getSubmissionDirectory()
submissionjson = submissionDirectory+"submission.json"
language = getLanguages()
jsonfile = []
solvedSubmissions = {}
rateLimitedQuestions = {}