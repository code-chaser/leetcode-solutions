// https://leetcode.com/problems/reverse-integer

/*
~~~~~~~~~~~~~~~~~~~~~~~~~~~
--||author : codechaser||-- 
~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/
class Solution
{
public:
    int reverse(int x)
    {
        bool negative = false;
        if (x < 0)
            negative = true;

        if (x == 0 || x == INT_MIN)
        {
            return 0;
        }

        x = abs(x);

        int ans = 0;
        int digits = floor(log10(x)) + 1;
        int multi = pow(10, digits - 1);

        bool ok = false;
        while (x)
        {
            if (digits == 10 && ok == false)
            {
                int max = INT_MAX;
                max = max / (multi);
                int temp = max % 10;
                if (x % 10 > temp && ok == false)
                {
                    return 0;
                }
                else if (x % 10 < temp)
                {
                    ok = true;
                }
            }
            ans += multi * (x % 10);
            multi /= 10;
            x /= 10;
        }
        if (negative)
            ans *= -1;
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