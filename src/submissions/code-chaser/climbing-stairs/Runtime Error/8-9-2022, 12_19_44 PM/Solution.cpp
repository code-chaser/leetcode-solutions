// https://leetcode.com/problems/climbing-stairs

class Solution {
private:
    vector<int> dp;
public:
    int climb(int i) {
        if (i == 0)
            return 0;
        if (dp[i - 1])
            return dp[i - 1];
        return dp[i - 1] = climb(i - 1) + climb(i - 2);
    }
    int climbStairs(int n) {
        dp.resize(n);
        dp[0] = 1;
        dp[1] = 2;
        return climb(n);
    }
};