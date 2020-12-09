#!/usr/bin/python3
"""This module has methods to determine if all the boxes can be opened.
"""


def canUnlockAll(boxes):
    """Determines if all the boxes can be opened.

    Args:
        boxes (list): boxes is a list of lists.

    Returns:
        true: return True if all boxes can be opened, else return False
    """
    if len(boxes) == 0:
        return True

    boxes_count = len(boxes)
    checked = [False] * boxes_count
    check(boxes, 0, checked)

    return all(checked)


def check(box, index, checked):
    """check the box if not opened.

    Args:
        box (list): box to check.
        index (int): index of the box to check.
        checked (list): list of checked boxes.
    """
    if checked[index]:
        return
    checked[index] = True
    for i in box[index]:
        check(box, i, checked)
