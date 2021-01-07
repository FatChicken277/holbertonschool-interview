#!/usr/bin/python3
"""This module contains a function that returns the minimum operations."""


def minOperations(n):
    """minimum operations

    Args:
        n (int): given a number

    Returns:
        int: If n is impossible to achieve, return 0.
    """
    base = 0
    div = 2

    if n < 1:
        return 0

    while n > 1:
        while n % div == 0:
            base += div
            n = n/div
        div += 1

    return base
