from typing import List

letters = {
    '2': 'abc',
    '3': 'def',
    '4': 'ghi',
    '5': 'jkl',
    '6': 'mno',
    '7': 'pqrs',
    '8': 'tuv',
    '9': 'wxyz'
}

class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        res:List[str] = []
        length = len(digits)

        if not digits: return res

        def backtrack(n, s):
            if n == length:
                res.append(s)
                return

            for c in letters[digits[n]]:
                backtrack(n+1, s + c)

        backtrack(0, '')

        return res

s = Solution()

print(s.letterCombinations('23'))
