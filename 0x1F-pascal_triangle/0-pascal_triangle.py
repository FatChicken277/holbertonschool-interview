#!/usr/bin/python3
"""
This module contains the pascal_triangle method
"""
import math


def pascal_triangle(n):
    result = []

    for count in range(n):
        row = []

        for element in range(count + 1):
            a = math.factorial(count)
            b = math.factorial(element) * math.factorial(count - element)

            row.append(int(a / b))

        result.append(row)

    return result
