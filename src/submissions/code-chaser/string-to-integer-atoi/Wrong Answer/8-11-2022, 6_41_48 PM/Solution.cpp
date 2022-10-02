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
        if (start) start--;
        neg = (s[start] == '-');
        if (s[start] == '-' || s[start] == '+')
            start++;
        while ((start < s.size()) && ('0' <= s[start]) && (s[start] <= '9')){
            cout<<"iteration: start="<<start<<", res="<<res<<"\n";
            res *= 10, res += (s[start++] - '0');
            cout<<"now: start="<<start<<", res="<<res<<"\n";
            if (neg) {
                if (res > 2147483648LL)
                    return INT_MIN;
            }
            if (res > INT_MAX)
                return INT_MAX;
            cout<<"now: start="<<start<<", res="<<res<<"\n";
        }
        if(neg)
            return 0 - res;
        return res;
    }
};