from src.service_async import *
from src.service_sync import *
from src.init import *
from dotenv import load_dotenv
from dotenv import set_key
import click

load_dotenv()

@click.group()
# @click.command()
@click.option('--github-token','-gt', 'git',  help='Set Github token.')
@click.option('--submission-directory', '-sd', 'directory',  help='Directory of solution files.')
@click.option('--repository', '-r', 'repo',  help='Github repository URL.')
@click.option('--leetcode-session','-ls', 'session',   help='Set leetcode session variable.')
@click.option('--leetcode-cookie', '-lc', 'cookie',  help='Set leetcode cookie.')
@click.option('--all', '-a', 'isAll',  help='Get all submissions.')
def cli(git, directory, repo, session, cookie):
    """Simple program that upload your leetcode solutions to github repository."""
    
    if directory:
        '''Directory of solution files.'''
        set_key('.env', 'SUBMISSION_DIRECTORY', directory)
        click.echo('Added successfully')

    if repo:
        '''Github repository URL.'''
        set_key('.env', 'REPOSITORY_URL', repo)
        click.echo('Added successfully')

    if session:
        '''Set leetcode session variable.'''
        set_key('.env', 'LEETCODE_SESSION', session)
        click.echo('Added successfully')

    if cookie:
        '''Set Leetcode cookie'''
        set_key('.env', 'LEETCODE_COOKIE', cookie)
        click.echo('Added successfully')

    if git:
        '''Set Github token'''
        set_key('.env', 'GITHUB_TOKEN', git)
        click.echo('Added successfully')

@cli.command("download-submission")
def get_all_submissions(isAll, id=None):
    if isAll:
        downloadAllSubmissions()
    else:
        downloadSubmission(id)   

@cli.command("ls-questions")
def get_all_submissions():
    return

# @cli.command("download-submission")
# @click.argument('questionId')
# def get_submissions(questionId):
#     downloadSubmission(questionId)

if __name__ == '__main__':
    cli()
# downloadAllSubmissions()
# downloadSubmission(int(input("Enter Question Id :")))

