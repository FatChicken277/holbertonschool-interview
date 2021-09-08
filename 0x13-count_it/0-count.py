#!/usr/bin/python3
"""This module is in charge of making the connection with the
    api and parses the title of all hot articles, and prints a
    sorted count of given keywords."""
import requests


def recurse(subreddit, hot_list=[], after=""):
    """This method returns a list containing the titles of all
        hot articles for a given subreddit"""
    headers = {"user-agent": "1637-holberton"}

    if after is None:
        return hot_list

    if after == "":
        r = requests.get('https://www.reddit.com/r/{}/hot.json'.format(
            subreddit), headers=headers, allow_redirects=False)
    else:
        r = requests.get(
            'https://www.reddit.com/r/{}/hot.json?after={}'.format(
                subreddit, after), headers=headers, allow_redirects=False)

    if r.status_code != 200:
        return None

    after = r.json().get("data").get("after")

    for child in r.json().get("data").get("children"):
        hot_list.append(child.get("data").get("title"))

    return recurse(subreddit, hot_list, after)


def count_words(subreddit, word_list):
    """This method parses the title of all hot articles,
        and prints a sorted count of given keywords."""
    list_all = {}

    hot_subreddits = recurse(subreddit)
    if hot_subreddits is None:
        return

    lowered_words = (map(lambda x: x.lower(), word_list))
    deduplicated_words = list(dict.fromkeys(lowered_words))

    for word in deduplicated_words:
        total = 0
        for hot_subreddit in hot_subreddits:
            if word in hot_subreddit.lower():
                total += 1
        if total > 0:
            list_all[word] = total

    result = sorted(list_all.items(), key=lambda x: x[1], reverse=True)
    for k, v in result:
        print("{}: {}".format(k, v))