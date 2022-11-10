# https://leetcode.com/problems/jump-game-ii/


from typing import List


class Solution:
    def jump(self, nums: List[int]) -> int:
        num_len = len(nums)
        current = 0
        jumps = 0

        if num_len <= 1: return 0

        while current < num_len - 1:
            next_jump_idx = current + nums[current]
            longest_next_jump_finish_idx = next_jump_idx

            if longest_next_jump_finish_idx >= num_len - 1: return jumps + 1

            for j in range(nums[current] + 1):
                jump_idx = current + j

                if jump_idx == num_len - 1:
                    break

                current_jump_finish_idx = nums[jump_idx] + jump_idx

                # Calculate max length of all possible next jumps
                if current_jump_finish_idx > longest_next_jump_finish_idx:
                    longest_next_jump_finish_idx = current_jump_finish_idx
                    next_jump_idx = jump_idx

            current = next_jump_idx
            jumps += 1

        return jumps

s = Solution()

assert s.jump([7,0,9,6,9,6,1,7,9,0,1,2,9,0,3]) == 2
assert s.jump([2,3,1]) == 1
assert s.jump([1,2,0,1]) == 2
assert s.jump([2,3,1,1,4]) == 2
assert s.jump([1,2]) == 1
