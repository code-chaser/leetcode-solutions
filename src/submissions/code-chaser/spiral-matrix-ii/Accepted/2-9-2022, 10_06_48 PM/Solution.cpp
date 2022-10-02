// https://leetcode.com/problems/spiral-matrix-ii

/*
~~~~~~~~~~~~~~~~~~~~~~~~~~~
--||author : codechaser||--
~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/
class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> matrix(n, vector<int>(n));
        int dir = 0;
        int startrow = 0, startcol = 0, endrow = n, endcol = n;
        int x = 0;

        for (int count = 0; count < (n + 1) / 2; count++)
        {
            for (int i = startcol; i < endcol; i++)
                matrix[startrow][i] = ++x;
            startrow++;

            for (int i = startrow; i < endrow; i++)
                matrix[i][endcol - 1] = ++x;
            endcol--;

            for (int i = endcol - 1; i >= startcol; i--)
                matrix[endrow - 1][i] = ++x;
            endrow--;

            for (int i = endrow - 1; i >= startrow; i--)
                matrix[i][startcol] = ++x;
            startcol++;
        }
        return matrix;
    }
};
/*
    |---------------------------------------------------|
    |||   https://codeforces.com/profile/codechaser   |||
    |||   https://www.codechef.com/users/codechaser   |||
    |||        https://github.com/code-chaser         |||
    |---------------------------------------------------|
*/