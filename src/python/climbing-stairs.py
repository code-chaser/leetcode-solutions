#https://leetcode.com/problems/climbing-stairs/

class Solution:
    temp ={
        1 : 1,
        2 : 2
    }
    def climbStairs(self, n: int) -> int:
        if n in self.temp:
            return self.temp[n]
        else:
            self.temp[n] = self.climbStairs(n-1) + self.climbStairs(n-2)
            return self.temp[n]