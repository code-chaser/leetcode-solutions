// https://leetcode.com/problems/letter-combinations-of-a-phone-number

/*
~~~~~~~~~~~~~~~~~~~~~~~~~~~
--||author : codechaser||-- 
~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/
class Solution
{
public:
    void recursive(string digits, vector<string> &res, map<int, string> m, string ans)
    {
        if (digits.length() == 0)
            res.push_back(ans);

        int d = (digits[0] - '0');

        for (int i = 0; i < m[d].length(); i++)
            recursive(digits.substr(1), res, m, ans + m[d][i]);
    }

    vector<string> letterCombinations(string digits)
    {
        if (digits == "")
            return {};
        map<int, string> m;
        m[2] = "abc";
        m[3] = "def";
        m[4] = "ghi";
        m[5] = "jkl";
        m[6] = "mno";
        m[7] = "pqrs";
        m[8] = "tuv";
        m[9] = "wxyz";
        vector<string> res;
        recursive(digits, res, m, "");

        return res;
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