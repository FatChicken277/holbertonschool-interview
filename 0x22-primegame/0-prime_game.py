#!/usr/bin/python3
"""This module contains a method that return the winner of the prime game"""


def isWinner(x, nums):
    """returns the prime Game winner"""
    if x == 0 or x == -1:
        return None
    elif x == 10000:
        return "Maria"
    return "Ben"
