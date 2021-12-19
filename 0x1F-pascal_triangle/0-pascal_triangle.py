#!/usr/bin/python3
"""
This module contains the pascal_triangle method
"""


def binomialCoeff(n, k):
    """
    Return the binomial coefficient
    """
    res = 1
    if (k > n - k):
        k = n - k
    for i in range(0, k):
        res = res * (n - i)
        res = res // (i + 1)

    return res


def pascal_triangle(n):
    """
    returns a list of lists of integers representing the Pascals triangle of n
    """
    result = []

    for count in range(n):
        row = []

        for element in range(count + 1):
            row.append(binomialCoeff(count, element))

        result.append(row)

    return result
