// https://leetcode.com/problems/string-to-integer-atoi

class Solution {
public:
    int myAtoi(string s) {
        int start = 0;
        long long res = 0;
        bool neg = 0;
        while ((start < s.size()) && (s[start] == ' ')) start++;
        if (start >= s.size())
            return 0;
        neg = (s[start] == '-');
        if (s[start] == '-' || s[start] == '+')
            start++;
        while ((start < s.size()) && ('0' <= s[start]) && (s[start] <= '9')){
            res *= 10, res += (s[start++] - '0');
            if (neg) {
                if (res > 2147483648LL)
                    return INT_MIN;
            }
            else if (res > INT_MAX)
                return INT_MAX;
        }
        if(neg)
            return 0 - res;
        return res;
    }
};