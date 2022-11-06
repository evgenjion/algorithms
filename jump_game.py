from typing import List

# https://leetcode.com/problems/jump-game/

# You are given an integer array nums.
# You are initially positioned at the array's first index,
# and each element in the array represents your maximum jump length at that position.

# Return true if you can reach the last index, or false otherwise.

# Input: nums = [2,3,1,1,4]
# Output: true

class Solution:
    # "greedy" algorithm
    def canJump(self, nums: List[int]) -> bool:
        lastIndex = len(nums) - 1
        lastReachableIndex = lastIndex

        for i in range(lastIndex, -1, -1):
            if (i + nums[i]) >= lastReachableIndex:
                lastReachableIndex = i


        if lastReachableIndex == 0: return True

        return False

    # dynamic programming. O(n^2) with optimizations
    def canJump_mySlowSolution(self, nums: List[int]) -> bool:
        # dp array
        canJumpArr = [False for _ in range(len(nums))]
        maxJumpIndexSoFar = 0

        if len(nums) == 0: return True
        canJumpArr[0] = True

        for i, currentJumpMax in enumerate(nums):
            if canJumpArr[i] is False: break
            if maxJumpIndexSoFar > (i + currentJumpMax): continue

            for jump in range(1, currentJumpMax + 1):
                jumpIdx = i + jump

                if jumpIdx >= len(nums): break

                maxJumpIndexSoFar = max(maxJumpIndexSoFar, jumpIdx)

                canJumpArr[jumpIdx] = True

            if canJumpArr[-1] is True: return True

        return False


s = Solution()

assert s.canJump([2,3,1,1,4]) == True
assert s.canJump([3,2,1,0,4]) == False
assert s.canJump([0,2,3]) == False
