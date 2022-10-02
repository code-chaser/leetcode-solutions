// https://leetcode.com/problems/factorial-trailing-zeroes

/*
~~~~~~~~~~~~~~~~~~~~~~~~~~~
--||author : codechaser||--
~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/
class Solution
{
public:
    int trailingZeroes(int n)
    {
        int ans = 0;
        while (n / 5)
            ans += (n / 5), n /= 5;
        return ans;
    }
};
/*
    |---------------------------------------------------|
    |||   https://codeforces.com/profile/codechaser   |||
    |||   https://www.codechef.com/users/codechaser   |||
    |||        https://github.com/code-chaser         |||
    |---------------------------------------------------|
*/