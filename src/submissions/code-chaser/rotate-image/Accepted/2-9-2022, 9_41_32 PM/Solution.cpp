// https://leetcode.com/problems/rotate-image

/*
~~~~~~~~~~~~~~~~~~~~~~~~~~~
--||author : codechaser||--
~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/
class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 0; i < m / 2; i++)
        {
            vector<int> temp = matrix[i];
            matrix[i] = matrix[m - 1 - i];
            matrix[m - 1 - i] = temp;
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < i; j++)
            {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
    }
};
/*
    |---------------------------------------------------|
    |||   https://codeforces.com/profile/codechaser   |||
    |||   https://www.codechef.com/users/codechaser   |||
    |||        https://github.com/code-chaser         |||
    |---------------------------------------------------|
*/