# https://leetcode.com/problems/roman-to-integer/

class Solution:
    def romanToInt(self, s: str) -> int:
        roman_dic = {"I": 1, "V": 5, "X": 10, "L": 50, "C": 100, "D": 500, "M": 1000}
        ans = 0

        for i in range(len(s)):

            if i != 0 and roman_dic[s[i - 1]] < roman_dic[s[i]]:
                ans = ans + roman_dic[s[i]] - roman_dic[s[i - 1]] * 2
            else:
                ans = ans + roman_dic[s[i]]

        return ans