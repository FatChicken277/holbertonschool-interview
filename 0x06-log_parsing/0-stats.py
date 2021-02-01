#!/usr/bin/python3
"""This module contains a script that reads stdin line by line
    and computes metrics.
"""
import sys

total_size = 0
status_codes = {"200": 0, "301": 0, "400": 0, "401": 0,
                "403": 0, "404": 0, "405": 0, "500": 0}

try:
    for num, line in enumerate(sys.stdin, 1):
        if len(line.split()) != 9:
            continue

        if line.split()[-2] in status_codes and line.split()[-2].isnumeric():
            status_codes[line.split()[-2]] += 1

        if line.split()[-1].isnumeric():
            total_size += int(line.split()[-1])

        if num % 10 == 0:
            print("File size: {}".format(total_size))
            for key, val in sorted(status_codes.items()):
                if val != 0:
                    print("{}: {}".format(key, val))
finally:
    print("File size: {}".format(total_size))
    for key, val in sorted(status_codes.items()):
        if val != 0:
            print("{}: {}".format(key, val))
