# https://leetcode.com/problems/swap-nodes-in-pairs/description/
from typing import Optional

from my_py_helpers.list import ListNode

class Solution:
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head: return None

        f = head
        s = head.next

        if s: head = s

        while f and s:
            #swap
            t = s.next
            # f - s - t - 4
            f.next = t
            s.next = f
            # s - f  - t - 4

            p = f
            f = t

            if f:
                s = f.next
            # 1 - p - f - s

                if s: p.next = s
            # 1 - p - f - s


            # 1 - p - f - s - t - 4

        return head

l = ListNode.init_from_list([1,2,3,4])

s = Solution()
s.swapPairs(l)

ListNode.print(l)
