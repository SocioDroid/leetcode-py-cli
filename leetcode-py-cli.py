from src.service_async import *
from src.service_sync import *
from src.init import *
from src.github import initGit
from dotenv import load_dotenv, set_key
import argparse
from tabulate import tabulate

load_dotenv()

parser = argparse.ArgumentParser(
    description='''

                ''',
    prog="leetcode-py-cli",
)

parser.add_argument(
    "-a",
    "--all",
    help="Download all submissions from Leetcode",
    action='store_true',
    default=0,
)

parser.add_argument(
    "-f",
    "--force-update",
    help="Forcefully update all solution.",
    action='store_true',
    default=0,
)

parser.add_argument(
    "-s",
    "--submission",
    help="Download specific submission from Leetcode",
    metavar='id'
)

parser.add_argument(
    "-ls",
    "--list-questions",
    help="List solved questions with statistics",
    action='store_true',
    default=0,
)

parser.add_argument(
    "-l",
    "--login",
    help="Login to Leetcode",
    # metavar=('csrf', 'session'),
    # nargs=2
    action='store_true',
    default=0,
)

parser.add_argument(
    "-g",
    "--github",
    help="Push your code to github",
    action='store_true',
    default=0,
)

parser.add_argument("-v", "--version", action="version", version="%(prog)s 1.0")
args = parser.parse_args()

if args.all:
    downloadAllSubmissions()

elif args.submission:
    downloadSubmission(int(args.submission))

elif args.list_questions:    
    downloadAllSubmissions()
    ls = []
    for i in jsonfile:
        j =  list(i.values())
        ls.append([j[0], j[1], j[4], j[5], j[6], j[7]])

    print(tabulate(sorted(ls, key= lambda x : x[0]), headers=["No.","Title", 'Submitted On', 'Memory', 'Time', 'Langauge'], tablefmt='fancy_grid'))

elif args.login:
    # Add a check
    if not check():
        session = input("Enter LEETCODE_SESSION : ")
        csrf = input("\nEnter csrftoken : ")
        set_key('.env', 'LEETCODE_SESSION', session)
        set_key('.env', 'LEETCODE_CSRFTOKEN', csrf)
    else:
        inp = input("You are already Logged in. Do you still want to change the details.[Y/n] : ")
        if inp.lower() == 'y':
            session = input("Enter LEETCODE_SESSION : ")
            csrf = input("\nEnter csrftoken : ")
            set_key('.env', 'LEETCODE_SESSION', session)
            set_key('.env', 'LEETCODE_CSRFTOKEN', csrf)
        
elif args.github:
    # Add a check
    if not checkGithubToken():
        git = input('Enter Github token : ')
        set_key('.env', 'GITHUB_TOKEN', git)

    downloadAllSubmissions()
    initGit() 
elif args.force_update:
    init.availableSubmissions = []
    downloadAllSubmissions()
else:
    parser.print_help()