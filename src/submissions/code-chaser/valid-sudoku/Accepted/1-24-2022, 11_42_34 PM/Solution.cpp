// https://leetcode.com/problems/valid-sudoku

/*
~~~~~~~~~~~~~~~~~~~~~~~~~~~
--||author : codechaser||-- 
~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/
class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        vector<bool> row(9, 0), col(9, 0), block(9, 0);
        //Row and Col check
        for (int k = 0; k < 81; k++)
        {
            int i = k / 9;
            int j = k % 9;
            //Row
            int n = board[i][j] - '1';
            if (n != '.' - '1')
            {
                if (row[n])
                    return false;
                row[n] = true;
            }

            //Col
            int m = board[j][i] - '1';
            if (m != '.' - '1')
            {
                if (col[m])
                    return false;
                col[m] = true;
            }

            //block
            int a = (i % 3) * 3 + j / 3;
            int b = (i / 3) * 3 + j % 3;
            n = board[a][b] - '1';
            if (n != '.' - '1')
            {
                if (block[n])
                    return false;
                block[n] = true;
            }
            if (j == 8)
            {
                row = col = block = {0, 0, 0, 0, 0, 0, 0, 0, 0};
            }
        }
        return true;
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