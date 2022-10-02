// https://leetcode.com/problems/max-points-on-a-line

/*
~~~~~~~~~~~~~~~~~~~~~~~~~~~
--||author : codechaser||--
~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/
#include <map>
class Solution
{
public:
    int maxPoints(vector<vector<int>> &points)
    {
        int n = points.size(), ans = 1;
        for (int i = 0; i < n; i++)
        {
            int infinity = 0;
            map<long double, int> cnt;
            for (int j = 0; j < n; j++)
            {
                if ((points[i][0] - points[j][0]))
                    cnt[(long double)(points[i][1] - points[j][1]) / (points[i][0] - points[j][0])] += 1;
                else if (points[i][1] - points[j][1])
                    infinity++;
            }
            ans = max(ans, infinity + 1);
            for (auto j : cnt)
                ans = max(ans, j.second + 1);
        }
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