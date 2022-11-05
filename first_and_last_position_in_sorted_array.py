# https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
from typing import List

class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        l = self.binarySearchFindMostIndex(nums, target, True)

        if l == -1: return [l, l]

        r = self.binarySearchFindMostIndex(nums, target, False)

        return [l, r]

    def binarySearchFindMostIndex(self, nums: List[int], target: int, leftMost: bool) -> int:
        l, r = 0, len(nums)-1
        i = -1 # left(right)most index

        while l <= r:
            m = (l + r) // 2

            if target < nums[m]:
                r = m - 1
            elif target > nums[m]:
                l = m + 1
            else: # if equals continue to search leftmost or rightmost index
                i = m
                if leftMost:
                    r = m - 1
                else:
                    l = m + 1

        return i

    # O(N) in worst case
    def searchRange_first_take(self, nums: List[int], target: int) -> List[int]:
        l = r = -1
        length = len(nums)

        # boundaries of binary search
        lb = 0
        rb = length - 1

        if length == 0: return [l, r]

        while lb <= rb and lb >= 0 and rb < length:
            m = (lb + rb) // 2

            if target == nums[m]:
                l = r = m
                while l > 0 and nums[l - 1] == nums[l]: l -= 1
                while r < length-1 and nums[r + 1] == nums[r]: r += 1
                break

            if target < nums[m]:
                rb = m - 1
            else:
                lb = m + 1


        return [l, r]

#
arr = [0,1,2,3,4,5,6,7,8,8,8,8,8,8,9]

s = Solution()


# print(s.searchRange([1], 1))
print(s.searchRange(arr, 8))
# print(s.searchRange([2,2], 3))
