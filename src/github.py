import json
import os
import requests
from .generate_readme import generateReadme
from .config import  checkRepoURL, getGithubToken, getSubmissionDirectory
from dotenv import set_key

def createRepo():
    reponame = input("Enter the name of the repository: ")
    print("Reponame : " + reponame)
    headers = {
        'Authorization': "token "+getGithubToken(),
    }
    data = { 
        "name": reponame, 
        "private": False 
        }
    response = requests.post('https://api.github.com/user/repos', headers=headers, json=data)
    message = json.loads(response.content.decode('utf-8'))     
    print(response.status_code)
    if response.status_code == 422:
        print("Please try again! : GITHUB ERRROR"+ getGithubToken()+"\n"+response.text)
        return createRepo()    
    return json.loads(response.content.decode('utf-8'))

def pushRepo(response):
    
    os.chdir(getSubmissionDirectory())
    if not checkRepoURL():
        os.system("git init")
        url = "https://{}:{}@github.com/{}/{}.git".format(response["owner"]["login"], getGithubToken(), response["owner"]["login"], response["name"])
        os.system("git remote add origin "+url)
        # with open("../.env", "a") as myfile:
        #     myfile.write("\nGITHUB_REPO="+url)
        set_key('../.env', 'GITHUB_REPO', url)        
    os.system("git add -A")

    import glob

    list_of_files = glob.glob('code/*.*') # * means all if need specific format then *.csv
    latest_file = max(list_of_files, key=os.path.getmtime)

    os.system("git commit -m \"Added "+latest_file.split('/')[-1].split('.')[-2]+"\"")

    os.system("git branch -M main")
    
    os.system("git push -u origin main")

def initGit():
    generateReadme()
    response = None
    if not checkRepoURL():
        response = createRepo()
    pushRepo(response)
