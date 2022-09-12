# https://leetcode.com/problems/container-with-most-water/

from typing import List
# import math

class BruteForceSolution:
    def maxArea(self, height: List[int]) -> int:
        res = 0

        for l in range(len(height)):
            for r in range(l, len(height)):
                res = max(res, (r-l) * min(height[r], height[l]))
        return res

bs = BruteForceSolution()

class SlidingWindowSolution:
    def maxArea(self, height: List[int]) -> int:
        res = 0

        l = 0
        r = len(height) - 1
        while r > l:
            res = max(res, (r-l) * min(height[l], height[r]))

            if height[l] > height[r]:
                r -= 1
            else:
                l += 1

        return res


# print(bs.maxArea([1,8,6,2,5,4,8,3,7])) # 49
s = SlidingWindowSolution()

print(s.maxArea([1,8,6,2,5,4,8,3,7])) # 49
