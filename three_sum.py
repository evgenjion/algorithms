# https://leetcode.com/problems/3sum/

from typing import List

class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        res = []
        nums.sort()
        len_n = len(nums)

        for i in range(len_n - 2):
            if (i > 0 and nums[i - 1] == nums[i]):
                continue

            target = -nums[i]

            l = i + 1
            r = len_n - 1

            # find two_sum of rest that equals target. @see ./two_sum2.py
            while l < r:
                sum = nums[l] + nums[r]
                if sum < target:
                    l += 1
                elif sum > target:
                    r -= 1
                else: # equals. push result, break loop
                    res.append([nums[i], nums[l], nums[r]])
                    # remove duplicates from the right side ([0, 0, 0])
                    while r > 0 and nums[r-1] == nums[r]:
                        r -= 1
                    r -= 1

        return res

bs = Solution()

# print(bs.threeSum([0,0,0])) # [[0,0,0]]
print(bs.threeSum([-1,0,1,2,-1,-4])) # [[-1,-1,2],[-1,0,1]]
