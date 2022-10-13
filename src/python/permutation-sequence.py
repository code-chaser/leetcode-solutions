# 60. Permutation Sequence
# https://leetcode.com/problems/permutation-sequence/

class Solution:
    def getPermutation(self, n: int, k: int) -> str:
        factorial = 1
        nums = []
        for i in range(1, n):
            factorial *= i
            nums.append(str(i))
        nums.append(str(n))
        
        k -= 1
        result = []
        while True:
            result.append(nums[k // factorial])
            nums.pop(k // factorial)
            if len(nums) == 0: break
            k %= factorial
            factorial //= len(nums)
        
        return "".join(result)
    