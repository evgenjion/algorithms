# Definition for singly-linked list.
from __future__ import annotations

class ListNode:
    """Definition of a singly-linked list"""
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

    @staticmethod
    def print(node: ListNode):
        print("{", end=' ')
        while node is not None:
            # print(node.val, end=', ')
            print(f'{node.val}, ', end='')
            node = node.next
        print("}")

    @staticmethod
    def init_from_list(arr=[]):
        """
        Initializes Singly-linked list from a given array
        """
        head = ListNode(0)
        cur = head

        for n in arr:
            cur.next = ListNode(n)
            cur = cur.next

        head = head.next

        return head
