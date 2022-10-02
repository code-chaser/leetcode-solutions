// https://leetcode.com/problems/string-to-integer-atoi

class Solution {
public:
    int myAtoi(string s) {
        int start = 0, res = 0;
        bool neg = 0;
        while ((start < s.size()) && (s[start++] == ' '));
        if (start >= s.size())
            return 0;
        start--;
        neg = (s[start] == '-');
        if (s[start] == '-' || s[start] == '+')
            start++;
        while ((start < s.size()) && ('0' <= s[start]) && (s[start] <= '9'))
            res *= 10, res += (s[start++] - '0');
        return (neg ? (-1) : (1)) * res;
    }
};