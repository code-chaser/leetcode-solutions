// https://leetcode.com/problems/decode-ways-ii

class Solution {
private:
    long long MOD = 1000000007;
public:
    int numDecodings(string s) {
        if (s[0] == '0')
            return 0;
        long long prev1 = 1, prev2 = 1, ans = 1;
        if (s[0] == '*')
            ans = prev2 = 9;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == '*' || s[i-1] == '*') {
                if (s[i] == '*' && s[i-1] == '*') {
                    // if both
                    ans *= 9;
                    ans %= MOD;
                    ans += ((prev1 * 15) % MOD);
                    ans %= MOD;
                }
                else if (s[i-1] == '*') {
                    // if only previous one
                    if (s[i] == '0')
                        ans = prev2 = 0;
                    ans += (prev1 * ((s[i] < '7') ? 2 : 1));
                    ans %= MOD;
                }
                else {
                    //if only current one
                    ans *= 9;
                    ans %= MOD;
                    ans += ((prev1 * ((s[i-1] != '1') ? ((s[i-1] == '2') * 6) : 9)) % MOD);
                    ans %= MOD;
                }
            }
            else {
                bool case1 = 0, case2 = 0;
                if (s[i] == '0')
                    ans = prev2 = 0, case1 = 1;
                if (((s[i-1] < '2') && (s[i-1] > '0')) || ((s[i-1] == '2') && (s[i] < '7')))
                    ans += prev1, case2 = 1;
                if (case1 && (!case2))
                    return 0;
            }
            prev1 = prev2;
            prev2 = ans;
        }
        return ans;
    }
};