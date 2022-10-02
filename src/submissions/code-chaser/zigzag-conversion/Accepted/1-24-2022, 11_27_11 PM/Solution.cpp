// https://leetcode.com/problems/zigzag-conversion

/*
~~~~~~~~~~~~~~~~~~~~~~~~~~~
--||author : codechaser||-- 
~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/
class Solution
{
public:
    string convert(string s, int numRows)
    {

        if (numRows == 1)
            return s;

        char arr[numRows][1000];

        for (int i = 0; i < numRows; i++)
            for (int j = 0; j < 1000; j++)
                arr[i][j] = '?';

        int direction = 1, i = 0, j = 0, k = 0;
        while (k < s.size())
        {
            if (i == numRows)
                direction = 1 - direction, i -= 2, j++;
            if (i == -1)
                direction = 1 - direction, i += 2, j++;
            if (direction)
                arr[i][j] = s[k], i++;
            else
                arr[i][j] = s[k], j++, i--;
            k++;
        }

        string ans = "";
        for (int i = 0; i < numRows; i++)
            for (int j = 0; j < 1000; j++)
                if (arr[i][j] != '?')
                    ans.push_back(arr[i][j]);

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