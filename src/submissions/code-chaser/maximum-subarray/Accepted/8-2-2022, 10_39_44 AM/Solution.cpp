// https://leetcode.com/problems/maximum-subarray

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int dp[nums.size()], ans;
        ans = dp[0] = nums[0];
        for (int i = 1; i < nums.size(); i++)
            dp[i] = max(dp[i - 1] + nums[i], nums[i]), ans = max(ans, dp[i]);
        return ans;
    }
};