# 1328. Break a Palindrome
# https://leetcode.com/problems/break-a-palindrome/

class Solution:
    def breakPalindrome(self, palindrome: str) -> str:
        if len(palindrome) == 1: return ""
        letters = list(palindrome)
        
        for i in range(len(letters) // 2):
            if letters[i] != 'a':
                letters[i] = 'a'
                return "".join(letters)
            
        letters[-1] = 'b'
        return "".join(letters)
    