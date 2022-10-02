// Solution Link - https://leetcode.com/submissions/detail/813414108/
class Solution 
{
public:
    long long int MOD = 1000000007;
    
    int helper(int i, int n, int k, int target,int curr_sum, vector<vector<int>> &dp)
    {
        if(i == n+1 and curr_sum == target) return 1;
            
        if(i>n || curr_sum>target) return 0;
        
        if(dp[i][curr_sum] != -1) return dp[i][curr_sum];
        
        int combinations = 0;
        
        for(int j=1;j<=k;j++)
        {
            combinations = (combinations + helper(i+1,n,k,target,curr_sum+j,dp)) % MOD;
        }
        
        return dp[i][curr_sum] = combinations;
    }
    
    int numRollsToTarget(int n, int k, int target) 
    {
        vector<vector<int>> dp(max(n,k)+1,vector<int> (target+1,-1));
        return helper(1,n,k,target,0,dp);
    }
};