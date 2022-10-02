// https://leetcode.com/problems/length-of-last-word

/*
~~~~~~~~~~~~~~~~~~~~~~~~~~~
--||author : codechaser||--
~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/
class Solution
{
public:
    int lengthOfLastWord(string str)
    {
        int num = str.size();

        int prev = -1;
        int count = 0;
        for (int i = num - 1; i >= 0; i--)
        {
            if (prev == -1 && str[i] == ' ')
            {
                prev = -1;
            }
            else if (prev == -1 && str[i] != ' ')
            {
                count++;
                prev = 1;
            }
            else if (prev == 1 && str[i] != ' ')
            {
                count++;
                prev = 1;
            }
            else if (prev == 1 && str[i] == ' ')
            {
                // count++;
                // prev=1;
                break;
            }
        }

        return count;
    }
};
/*
    |---------------------------------------------------|
    |||   https://codeforces.com/profile/codechaser   |||
    |||   https://www.codechef.com/users/codechaser   |||
    |||        https://github.com/code-chaser         |||
    |---------------------------------------------------|
*/