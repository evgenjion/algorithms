# https://leetcode.com/problems/longest-palindromic-substring/

class Solution:
    def longestPalindrome(self, s: str) -> str:
        res = s[0] or ''
        maxLen = len(res)
        len_s = len(s)

        for i in range(len_s):
            l, r = i, i

            while (l >= 0 and r < len_s and s[l] == s[r]):
                if maxLen <= r - l + 1:
                    maxLen = r - l + 1
                    res = s[l:r+1]
                l -= 1
                r += 1

            # case with odd number of elements
            l, r = i, i+1

            while (l >= 0 and r < len_s and s[l] == s[r]):
                if maxLen <= r - l + 1:
                    maxLen = r - l + 1
                    res = s[l:r+1]
                l -= 1
                r += 1

        return res

s = Solution()

r = s.longestPalindrome('babad')

print(r)
