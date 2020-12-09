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
        return False

    boxes_count = len(boxes)
    checked = [False] * boxes_count
    check(boxes, 0, checked, boxes_count)

    return all(checked)


def check(box, index, checked, boxes_count):
    """check the box if not opened.

    Args:
        box (list): box to check.
        index (int): index of the box to check.
        checked (list): list of checked boxes.
        boxes_count (int): len of all boxes.
    """
    if index > boxes_count - 1:
        return
    if checked[index]:
        return

    checked[index] = True
    for i in box[index]:
        check(box, i, checked, boxes_count)
