// https://leetcode.com/problems/integer-to-roman

/*
~~~~~~~~~~~~~~~~~~~~~~~~~~~
--||author : codechaser||-- 
~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/
class Solution {
public:
    string intToRoman(int n) {
        unordered_map<int, string> mp;
        mp[1] = "I"; mp[5] = "V"; mp[10] = "X"; mp[50] = "L"; mp[100] = "C"; mp[500] = "D"; mp[1000] = "M";
        mp[4] = "IV"; mp[9] = "IX";
        mp[40] = "XL"; mp[90] = "XC";
        mp[400] = "CD"; mp[900] = "CM";
        int p = 0;
        string ans = "";
        while (n > 0) {
            int x = pow(10, p);
            int nm = x * (n % 10);
            n /= 10;
            if (mp.count(nm)) {
                ans = mp[nm] + ans;
            }
            else {
                int cnt = nm / x;
                if (cnt <= 5) {
                    for (int i = 0; i < cnt; i++) ans = mp[x] + ans;
                }
                else {
                    string t = mp[5 * x];
                    for (int i = 0; i < cnt - 5; i++) t += mp[x];
                    ans = t + ans;
                }
            }
            p++;
        }
        return ans;
    }
};
////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
    |---------------------------------------------------|
    |||   https://codeforces.com/profile/codechaser   |||
    |||   https://www.codechef.com/users/codechaser   |||
    |||        https://github.com/code-chaser         |||
    |---------------------------------------------------|
*/
////////////////////////////////////////////////////////////////////////////////////////////////////////////