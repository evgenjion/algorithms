# https://leetcode.com/problems/generate-parentheses/

from typing import List

class RecursiveSolution:
    def generateParenthesis(self, n: int) -> List[str]:
        filled_len = n * 2 # () for each n
        res: List[str] = []

        if n == 0: return res

        def gen(s: str):
            if len(s) == filled_len:
                res.append(s)
                return

            open_count = s.count('(')
            closed_count = s.count(')')

            if open_count < n:
                gen(s + '(')
            if closed_count < open_count:
                gen(s + ')')

        gen('')

        return res

class OneMoreSolution:
    def generateParenthesis(self, n: int) -> List[str]:
        stack: List[str] = []
        res: List[str] = []

        def backtrack(open_n, closed_n):
            if open_n == closed_n == n:
                res.append(''.join(stack))
                return
            if open_n < n:
                stack.append('(')
                backtrack(open_n + 1, closed_n)
                stack.pop() # wow. clear stack after backtrack
            if closed_n < open_n:
                stack.append(')')
                backtrack(open_n, closed_n + 1)
                stack.pop()

        backtrack(0, 0)
        return res

# s = RecursiveSolution()
s = OneMoreSolution()

print(s.generateParenthesis(3))
