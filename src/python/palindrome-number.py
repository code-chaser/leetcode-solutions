#https://leetcode.com/problems/palindrome-number/

class Solution:
    def isPalindrome(self, x: int) -> bool:
        y = str(x)
        lst = list(y)
        lst.reverse()
        y = "".join(lst)
        try:
            y = int(y)
        except:
            ValueError
        if x == y:
            return True
        else:
            return False