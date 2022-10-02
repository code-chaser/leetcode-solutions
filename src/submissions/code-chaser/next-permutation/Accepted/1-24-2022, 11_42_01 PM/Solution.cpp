// https://leetcode.com/problems/next-permutation

/*
~~~~~~~~~~~~~~~~~~~~~~~~~~~
--||author : codechaser||-- 
~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/
class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int n = nums.size();
        int i;
        int ind;
        for (i = nums.size() - 1; i >= 1; i--)
        {
            if (nums[i] > nums[i - 1])
            {
                ind = i;
                while (nums[i - 1] < nums[ind])
                {
                    ind++;
                    if (ind == n)
                        break;
                }
                swap(nums[ind - 1], nums[i - 1]);
                reverse(nums.begin() + i, nums.end());
                return;
            }
        }
        reverse(nums.begin(), nums.end());
        return;
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