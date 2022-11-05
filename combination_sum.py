from typing import List

# Input: candidates = [2,3,6,7], target = 7
# Output: [[2,2,3],[7]]

class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        res = []
        # for i to len(candidates) buildCombination(i,...) ?

        # for i in range(len(candidates)):
        self.buildCombination(0, candidates, [], target, 0, res)

        return res

    def buildCombination(
        self,
        sumSoFar: int,
        candidates: List[int],
        pathSoFar: List[int],
        target: int,
        i: int,
        res: List[List[int]]
    ):
        if sumSoFar > target: return
        if sumSoFar == target:
            res.append(pathSoFar)
            return

        for n in range(i, len(candidates)):
            self.buildCombination(
                sumSoFar + candidates[n],
                candidates,
                pathSoFar + [candidates[n]], # to N?
                target,
                n, # to N?
                res
            )


s = Solution()
print(s.combinationSum([2,3,6,7], 7))
