// https://leetcode.com/problems/container-with-most-water

/*
~~~~~~~~~~~~~~~~~~~~~~~~~~~
--||author : codechaser||-- 
~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/
class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int i = 0, j = height.size() - 1, ans = 0;
        while (i < j)
        {
            int temp = (j - i) * (min(height[j], height[i]));
            ans = max(temp, ans);
            if (height[j] > height[i])
                i++;
            else
                j--;
        }
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