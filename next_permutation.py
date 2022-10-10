# https://leetcode.com/problems/next-permutation/

from typing import List

# Tricky solution =/ better to look at the implementation explanation
class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """

        def reverse(l: int, r: int):
            while l < r:
                nums[l], nums[r] = nums[r], nums[l]
                l += 1
                r -= 1

        pivot = 0

        for i in range(len(nums) - 2, -1, -1):
            if nums[i] < nums[i + 1]:
                pivot = i

                min_idx = i+1
                # find element for swap
                for j in range(i+1, len(nums)):
                    if nums[min_idx] >= nums[j]  and nums[j] > nums[pivot]:
                        min_idx = j

                # swap
                nums[min_idx], nums[pivot] = nums[pivot], nums[min_idx]

                #reverse the rest
                reverse(pivot + 1, len(nums) - 1)

                return

        # if pivot == 0:
        nums.reverse()
            # return




        #     j = i - 1

        #     while j >= 0:
        #         if nums[j] < nums[i]:
        #             # permutation_exists = True
        #             nums[j], nums[i] = nums[i], nums[j]

        #             # TODO: sort from j+1 ASC to the end?
        #             k = j + 1
        #             while k < len(nums):
        #                 min_idx = k
        #                 m = k + 1

        #                 while m < len(nums):
        #                     if nums[min_idx] > nums[m]:
        #                         min_idx = m
        #                     m += 1

        #                 nums[min_idx], nums[k] = nums[k], nums[min_idx]
        #                 k += 1
        #             return
        #         j-=1

        # # if not permutation_exists:
        # nums.reverse() # O(N)?


arr1 = [4,2,0,2,3,2,0]
arr2 = [0,1,2,5,3,3,0]
arr = [1,2,3]

s = Solution()

# s.nextPermutation(arr2) # [0,1,3,0,2,3,5]
# print(arr2)

# s.nextPermutation(arr1) # [4,2,0,3,0,2,2]
# print(arr1)

s.nextPermutation(arr)
print(arr) # [1,3,2]


s.nextPermutation(arr)
print(arr) # [2, 1, 3]

s.nextPermutation(arr)
print(arr) # [2, 3, 1]

s.nextPermutation(arr)
print(arr) # [3,1,2]


s.nextPermutation(arr)
print(arr) # [1,2,3]
