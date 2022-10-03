//Solution-Link - https://leetcode.com/submissions/detail/753763392/
class Solution 
{
public:
    int f(vector<int> &prices, int state, int i,vector<vector<int>> &dp, int fee)
    {
        int n = prices.size();

        if(i == n) return 0;
        
        if(dp[i][state] != -1) return dp[i][state];
        
        int profit = 0;
        
        if(state)
        {
            profit = max(-prices[i] + f(prices,0,i+1, dp, fee),  0 + f(prices,1 ,i+1,dp, fee));
        }
        
        else
        {
            profit = max(prices[i]- fee + f(prices,1,i+1, dp, fee),  0 + f(prices, 0, i + 1, dp, fee));
        }
        return dp[i][state] = profit;
    }
    
    int maxProfit(vector<int>& prices, int fee) 
    {
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        return f(prices, 1,0, dp, fee);
    }
};