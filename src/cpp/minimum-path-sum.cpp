class Solution {
public:
    
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid);
        int r = grid.size();
        int c = grid[0].size();
        for(int i = 0; i<grid.size(); i++){
            for(int j = 0; j<grid[0].size(); j++){
                if(i-1 >= 0 && j-1 >= 0)
                    dp[i][j] += min(dp[i-1][j], dp[i][j-1]);
                else{
                    if(i-1>=0)
                        dp[i][j] += dp[i-1][j];
                    if(j-1>= 0)
                        dp[i][j] += dp[i][j-1];
                }
            }
        }
        
        return dp[r-1][c-1];
    }
};