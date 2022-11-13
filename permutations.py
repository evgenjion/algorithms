# https://leetcode.com/problems/permutations/

from typing import List


class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        res = []

        self.gen_permutation(nums, res, [], nums)

        return res

    def gen_permutation(self, nums: List[int], res: List[int], current: List[int], tail: List[int]) -> List[List[int]]:
        """
        backtrack solution
        """

        if len(tail) == 1:
            res.append(current + tail)
            return

        for i, n in enumerate(tail):
            self.gen_permutation(nums, res, current + [n], tail[:i] + tail[i + 1:])

        return res

s = Solution()
print(s.permute([1,2,3]))
