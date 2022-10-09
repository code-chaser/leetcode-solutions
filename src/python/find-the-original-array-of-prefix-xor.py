# 2433. Find The Original Array of Prefix Xor
# https://leetcode.com/problems/find-the-original-array-of-prefix-xor/

class Solution:
    def findArray(self, pref: List[int]) -> List[int]:
        result = [pref[0]]
        for i in range(1, len(pref)):
            result.append(pref[i - 1] ^ pref[i])
        return result
