import json
import os
import requests
from .generate_readme import generateReadme
from .config import  checkRepoURL, getGithubToken, getSubmissionDirectory

token = getGithubToken()

def createRepo():
    reponame = input("Enter the name of the repository: ")
    headers = {
        'Authorization': "token "+token,
    }
    data = { 
        "name": reponame, 
        "private": False 
        }
    response = requests.post('https://api.github.com/user/repos', headers=headers, json=data)
    message = json.loads(response.content.decode('utf-8'))     
    print(response.status_code)
    if response.status_code == 422:
        print(message["errors"][0]["message"])
        print("Please try again!")
        return createRepo()    
    return json.loads(response.content.decode('utf-8'))

def pushRepo(response):
    
    os.chdir(getSubmissionDirectory())
    if not checkRepoURL():
        os.system("git init")
        url = "https://{}:{}@github.com/{}/{}.git".format(response["owner"]["login"], getGithubToken(), response["owner"]["login"], response["name"])
        os.system("git remote set-url origin "+url)
        with open("../.env", "a") as myfile:
            myfile.write("\nGITHUB_REPO="+url)
    os.system("git add -A")
    os.system("git commit -m 'Created using leetcode-cli'")
    os.system("git branch -M main")
    
    os.system("git push -u origin main")

def initGit():
    generateReadme()
    response = None
    if not checkRepoURL():
        response = createRepo()
    pushRepo(response)
