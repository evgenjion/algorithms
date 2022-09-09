# https://leetcode.com/problems/longest-substring-without-repeating-characters/
# Accepted but not uses sliding window
class SolutionFirstTake:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if (len(s) == 1): return 1
        max_num = 0

        for i, s_i in enumerate(s):
            current_length = 1
            used = set(s_i)

            # for s_j in s[i+1:]:
            for j in range(i+1, len(s)):
                if (s[j] in used):
                    max_num = max(max_num, current_length)
                    break
                else:
                    used.add(s[j])
                    current_length += 1

            max_num = max(max_num, current_length)
        return max_num

class Solution:
    """
    Implement sliding window algorithm
    """
    def lengthOfLongestSubstring(self, s: str) -> int:
        longest = 0
        start = end = 0
        used = set()

        for end in range(len(s)):
            while s[end] in used:
                used.remove(s[start])
                start += 1
            used.add(s[end])

            longest = max(longest, end - start + 1)


        return longest

s = Solution()


# print(s.lengthOfLongestSubstring('pwwkew'))
print(s.lengthOfLongestSubstring('abcabcbb')) # 3 expected
# print(s.lengthOfLongestSubstring('nfpdmpi')) # 5 expected
# print(s.lengthOfLongestSubstring("bbbbb"))

# print(s.lengthOfLongestSubstring('au')) # 0
