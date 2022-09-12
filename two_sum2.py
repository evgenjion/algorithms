from typing import List

class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        l = 0
        r = len(numbers) - 1
        while l < r:
            tmp_sum = numbers[l] + numbers[r]
            if tmp_sum == target:
                return [l+1, r+1]
            if tmp_sum > target:
                r -= 1
            else:
                l += 1
        return None

s = Solution()

print(s.twoSum([2,7,11,15], 9))
