# 2434. Using a Robot to Print the Lexicographically Smallest String
# https://leetcode.com/problems/using-a-robot-to-print-the-lexicographically-smallest-string/

class Solution:
    def robotWithString(self, s: str) -> str:
        stack = []
        result = []
        smallest_from_right = [""] * len(s)
        smallest_from_right[-1] = s[-1]
        
        for i in range(len(smallest_from_right) - 2, -1, -1):
            smallest_from_right[i] = min(s[i], smallest_from_right[i + 1])
        
        for i in range(len(s)):
            while stack and stack[-1] <= smallest_from_right[i]:
                result.append(stack.pop())
            stack.append(s[i])
        
        while stack:
            result.append(stack.pop())
        
        return "".join(result)
        