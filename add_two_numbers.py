from typing import Optional
from my_py_helpers.list import ListNode

class Solution:
    def addTwoNumbers(
      self,
      l1: Optional[ListNode],
      l2: Optional[ListNode]
    ) -> Optional[ListNode]:
        head = ListNode(0)
        cur = head
        sum = 0

        while l1 or l2:
            sum = sum//10
            cur.next = ListNode(sum)
            cur = cur.next

            if l1:
                sum += l1.val
                l1 = l1.next

            if l2:
                sum += l2.val
                l2 = l2.next

            rest = sum % 10
            cur.val = rest
            sum -= rest

        if sum != 0:
            cur.next = ListNode(sum//10)

        head = head.next

        return head


l1 = ListNode.init_from_list([9, 2, 8, 9])
l2 = ListNode.init_from_list([4, 5, 6])

ListNode.print(l1)
ListNode.print(l2)

s = Solution()
r = s.addTwoNumbers(l1, l2)

ListNode.print(r)
