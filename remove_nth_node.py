# https://leetcode.com/problems/remove-nth-node-from-end-of-list/

from typing import Optional
from my_py_helpers.list import ListNode

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        if head is None: return head

        nodes = []
        cur = head

        while cur:
            nodes.append(cur)
            cur = cur.next

        length = len(nodes)

        if n == length:
            head = head.next
        else:
            nodes[length - n - 1].next = nodes[length - n].next

        return head

