
<h1 align="center">
  <br>
  <a href="https://github.com/SocioDroid/leetcode-py-cli/archive/main.zip"><img src="https://i.ibb.co/52jm2Mn/leetcodecli.png" alt="leetcode-py-cli"></a>
</h1>


<h4 align="center">A CLI utility integrated with LeetCode for accessing your submissions and many </h4>

<p align="center">
    <a href="https://www.python.org/">
    <img src="https://img.shields.io/badge/Made%20with-Python-1f425f.svg"
         alt="GitHub last commit">	
    <a href="https://github.com/SocioDroid/leetcode-py-cli/commits/master">
    <img src="https://img.shields.io/github/last-commit/SocioDroid/leetcode-py-cli.svg"
         alt="GitHub last commit">
    <a href="https://github.com/SocioDroid/leetcode-py-cli/issues">
    <img src="https://img.shields.io/github/issues-raw/SocioDroid/leetcode-py-cli.svg"
         alt="GitHub issues">
    <a href="https://github.com/SocioDroid/leetcode-py-cli/pulls">
    <img src="https://img.shields.io/github/issues-pr-raw/SocioDroid/leetcode-py-cli.svg"
         alt="GitHub pull requests">
    <a href="https://twitter.com/intent/tweet?text=Try this CS:GO AutoExec:&url=https%3A%2F%2Fgithub.com%2FArmynC%2FArminC-AutoExec">
    <img src="https://img.shields.io/twitter/url/https/github.com/SocioDroid/leetcode-py-cli.svg?logo=twitter"
         alt="GitHub tweet">
</p>

<p align="center">
  <a href="#about">About</a> •
  <a href="#installation">Installation</a> •
  <a href="#usage">Usage</a> •
  <a href="#features">Features</a> •
  <a href="#github-integration">Github Integration</a> • 
  <a href="#credits">Credits</a> •
</p>

---

## About

<table>
<tr>
<td>
leetcode-py-cli is a CLI utility to interact with LeetCode. We came up with this utility when we tried to upload our solutions to the Github repo, 
but found it to be a very tedious task to manually fetch the submissions.
We couldn't find any open source app which can fetch all the submissions that have been made by us. This is a 2-days fun project made out of curiosity.
We added some more features such as listing valid sumbissions, downloading individual submission, integrated it with github to auto-create a repo and push the
codes to it.
</td>
</tr>
</table>

## Installation

##### Downloading and installing steps:
* **[Download](https://github.com/SocioDroid/leetcode-py-cli/archive/main.zip)** the latest version of the repo or clone it using 

		git clone https://github.com/SocioDroid/leetcode-py-cli.git
* Install dependencies 
          
        pip install -r requirements.txt 

## Usage
	 python3 leetcode-py-cli.py -h
This will display help for the tool. Here are all the options it supports.

|          Command      |        Description                         |      Example                          |
|-----------------------|--------------------------------------------|---------------------------------------|
| -h, --help            | Show help and usage of tool                | leetcode-py-cli<span>.</span>py -h    |
| -l, --login           | Login to LeetCode                          | leetcode-py-cli<span>.</span>py -l    |
| -s id, --submission id| Download specific submission from LeetCode | leetcode-py-cli<span>.</span>py -s 10 |
| -a, --all             | Download all submissions from LeetCode     | leetcode-py-cli<span>.</span>py -a    |
| -f, --force-update    | Forcefully update all solution             | leetcode-py-cli<span>.</span>py -f    |
| -ls, --list-questions | List solved questions with statistics      | leetcode-py-cli<span>.</span>py -ls   |
| -g, --github          | Push your code to github                   | leetcode-py-cli<span>.</span>py -g    |
| -v, --version         | Show program's version number              | leetcode-py-cli<span>.</span>py -v    | 

## Features

<h1 align="left">
  <img src="static/leetcode-ls.svg" alt="leetcode-py-cli" width="700px"></a>
  <br>
</h1>

 - **Async support** to fetch all submissions.
 - Uses **LeetCode's GraphQL** to fetch data.
 - **Github's REST API** integration to auto-create repository.
 - Retrieve & push new submissions on the go.
