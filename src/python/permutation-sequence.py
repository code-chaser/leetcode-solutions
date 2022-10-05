#By KrishGaur1354
#https://leetcode.com/problems/permutation-sequence/

class Solution:
    def getPermutation(self, n: int, k: int) -> str:
        def fact(n):
            r = 1
            for i in range(2,n+1):
                r *= i
            return r
        
        nums = [str(i) for i in range(1,n+1)]
        s=''
        while(nums):
            div = fact(len(nums)-1)
            idx = 0
            while(k>div):
                idx += 1
                k -= div
                
            s += nums.pop(idx)
            
        return s
