// https://leetcode.com/problems/string-to-integer-atoi

class Solution {
public:
    int myAtoi(string s) {
        int start = 0;
        long long res = 0;
        bool neg = 0;
        while ((start < s.size()) && (s[start++] == ' '));
        if (start > s.size())
            return 0;
        if (start) start--;
        neg = (s[start] == '-');
        if (s[start] == '-' || s[start] == '+')
            start++;
        while ((start < s.size()) && ('0' <= s[start]) && (s[start] <= '9'))
            res *= 10, res += (s[start++] - '0');
        if (neg) {
            if (res > 2147483648LL)
                return -2147483648;
            return 0 - res;
        }
        if (res > 2147483647)
            return 2147483647;
        return res;
    }
};