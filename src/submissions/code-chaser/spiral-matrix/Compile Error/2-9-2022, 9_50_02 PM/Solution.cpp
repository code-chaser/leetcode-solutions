// https://leetcode.com/problems/spiral-matrix

/*
~~~~~~~~~~~~~~~~~~~~~~~~~~~
--||author : codechaser||--
~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/
class Solution
{
public:
    List<Integer> spiralOrder(int[][] matrix)
    {

        List<Integer> list = new ArrayList<>();

        if (matrix.length == 0 || matrix[0].length == 0)
            return list;

        int rowBegin = 0;
        int rowEnd = matrix.length - 1;
        int colBegin = 0;
        int colEnd = matrix[0].length - 1;

        while (rowBegin <= rowEnd && colBegin <= colEnd)
        {
            for (int i = colBegin; i <= colEnd; i++)
            {
                list.add(matrix[rowBegin][i]);
            }
            rowBegin++;

            for (int i = rowBegin; i <= rowEnd; i++)
            {
                list.add(matrix[i][colEnd]);
            }
            colEnd--;

            if (rowBegin <= rowEnd)
            {
                for (int i = colEnd; i >= colBegin; i--)
                {
                    list.add(matrix[rowEnd][i]);
                }
            }
            rowEnd--;

            if (colBegin <= colEnd)
            {
                for (int i = rowEnd; i >= rowBegin; i--)
                {
                    list.add(matrix[i][colBegin]);
                }
            }
            colBegin++;
        }
        return list;
    }
}
/*
    |---------------------------------------------------|
    |||   https://codeforces.com/profile/codechaser   |||
    |||   https://www.codechef.com/users/codechaser   |||
    |||        https://github.com/code-chaser         |||
    |---------------------------------------------------|
*/