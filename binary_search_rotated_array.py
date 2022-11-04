from typing import List

class Solution:

    def search(self, nums: List[int], target: int) -> int:
        l, r = 0, len(nums) - 1

        while l <= r:
            m = (l + r) // 2
            is_left_sorted = nums[m] >= nums[l]

            if target == nums[m]: return m

            if is_left_sorted:
                if target > nums[m] or nums[l] > target:
                    l = m + 1
                else:
                    r = m - 1
            else:
                if nums[m] > target or target > nums[r]:
                    r = m - 1
                else:
                    l = m + 1

        return -1



    # def wrong_search(self, nums: List[int], target: int) -> int:
    #     l, r = 0, len(nums) - 1

    #     while l <= r:
    #         m = (l + r) // 2
    #         is_left_sorted = nums[l] < nums[m]

    #         if nums[m] == target: return m

    #         if is_left_sorted:
    #             if target < nums[m]:
    #                 if target < nums[l]:
    #                     l = m + 1
    #                     continue
    #                 else:
    #                     r = m
    #                     continue
    #             else:
    #                 l = m + 1
    #                 continue
    #         else:
    #             if target < nums[m]:
    #                 # l = m + 1
    #                 r = m  # TODO: solve [1]
    #                 continue
    #             else:
    #                 if target > nums[r]:
    #                     r = m - 1
    #                     continue
    #                 else:
    #                     l = m + 1

    #     return -1

s = Solution()

print(s.search([5,1,2,3,4], 1))
print(s.search([3,1], 1))
print(s.search([4,5,6,7,0,1,2], 0))
