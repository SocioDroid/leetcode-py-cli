from src.service_async import *
from src.service_sync import *
from src.init import *
from dotenv import load_dotenv, set_key
import argparse
from tabulate import tabulate

load_dotenv()

parser = argparse.ArgumentParser(
    description="Simple program that upload your leetcode solutions to github repository.",
    prog="leetcode-python-cli",
)

parser.add_argument(
    "-a",
    "--all",
    help="Get All submissions from Leetcode",
    action='store_true',
    default=0,
)

parser.add_argument(
    "-q",
    "--get-question",
    help="Get specified problem id submissions from Leetcode",
    metavar='id'
)

parser.add_argument(
    "-ls",
    "--list-questions",
    help="Get specified problem id submissions from Leetcode",
    action='store_true',
    default=0,
)

parser.add_argument(
    "-l",
    "--login",
    help="Get specified problem id submissions from Leetcode",
    metavar=('csrf', 'session'),
    nargs=2
)

parser.add_argument(
    "-u",
    "--repository-url",
    help="Get specified problem id submissions from Leetcode",
    nargs=1,
    metavar='url'
)

parser.add_argument(
    "-g",
    "--github-token",
    help="Get specified problem id submissions from Leetcode",
    nargs=1,
    metavar='token'
)

parser.add_argument("-v", "--version", action="version", version="%(prog)s 1.0")
args = parser.parse_args()

if args.all:
    downloadAllSubmissions()

elif args.get_question:
    downloadSubmission(args.get_question)

elif args.list_questions:    
    downloadAllSubmissions()
    ls = []
    for i in jsonfile:
        j =  list(i.values())
        ls.append([j[0], j[1], j[4], j[5], j[6], j[7]])

    print(tabulate(sorted(ls, key= lambda x : x[0]), headers=["No.","Title", 'Submitted On', 'Memory', 'Time', 'Langauge'], tablefmt='fancy_grid'))

elif args.login:
    set_key('.env', 'LEETCODE_SESSION', args.login[0])
    set_key('.env', 'LEETCODE_CSRFTOKEN', args.login[1])

elif args.github_token:
    set_key('.env', 'GITHUB_TOKEN', args.github_token[0])
    
elif args.repository_url:
    set_key('.env', 'REPOSITORY_URL', args.repository_url)
        
else:
    parser.print_help()