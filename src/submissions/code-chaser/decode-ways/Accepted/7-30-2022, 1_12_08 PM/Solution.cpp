// https://leetcode.com/problems/decode-ways

class Solution {
public:
    int numDecodings(string s) {
        if (s[0] == '0')
            return 0;
        int prev1 = 1, prev2 = 1, ans = 1;
        for (int i = 1; i < s.size(); i++) {
            bool case1 = 0, case2 = 0;
            if (s[i] == '0')
                ans = prev2 = 0, case1 = 1;
            if (((s[i-1] < '2') && (s[i-1] > '0')) || ((s[i-1] == '2') && (s[i] < '7')))
                ans += prev1, case2 = 1;
            prev1 = prev2;
            prev2 = ans;
            if (case1 && (!case2))
                return 0;
        }
        return ans;
    }
};