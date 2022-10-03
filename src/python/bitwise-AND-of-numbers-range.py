# 201. Bitwise AND of Numbers Range
# https://leetcode.com/problems/bitwise-and-of-numbers-range/

class Solution:
    def rangeBitwiseAnd(self, left: int, right: int) -> int:
        zero_bits = 0
        while left != right:
            left >>= 1
            right >>= 1
            zero_bits += 1
        return left << zero_bits
