#https://leetcode.com/problems/powx-n/

class Solution:
    def myPow(self, x: float, n: int) -> float:
	    # Base case
        if n == 0:
            return 1
        # determine whether to divide by the answer 
        if n < 0: 
            div = True
        else:
            div = False
            
        n = abs(n) 
        ans = 1 
        while n>0:    
            ans *= x
            print(ans)
            n -= 1 # decrement n by 1
        
        return 1/ans if div else ans # divide by the answer if n is negative