//https://leetcode.com/problems/cherry-pickup/

class Solution {
public:
    int dp[51][51][51];
    int dfs(vector<vector<int>>& grid,int r1,int c1,int r2){
        int c2 = r1+c1-r2;
        if(r1>=grid.size() || r2>=grid.size() || c1 >= grid[0].size() || c2 >= grid[0].size() || grid[r1][c1] == -1 || grid[r2][c2] == -1){
            return INT_MIN;
        }
        
        if(r1 == grid.size()-1 && c1 == grid[0].size()-1){
            return grid[r1][c1];
        }
        if(dp[r1][c1][r2] != -1){
            return dp[r1][c1][r2];
        }
        
        int x1=0,x2=0;
        if(r1 == r2 && c1 == c2){
            x1 += grid[r1][c1];
        }
        else{
            x1 += grid[r1][c1];
            x2 += grid[r2][c2];
        }
        
        int a = dfs(grid, r1, c1+1, r2); // right, right
        int b = dfs(grid, r1+1, c1, r2+1); // bottom, bottom
        int c = dfs(grid, r1+1, c1, r2); // bottom, right
        int d = dfs(grid, r1, c1+1, r2+1); // right, bottom
        
        if(a == b && b == c && c == d && a == INT_MIN){
            return dp[r1][c1][r2] = INT_MIN;
        }
        return dp[r1][c1][r2] = x1 + x2 + max(max(a,b),max(c,d));
    }
    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        int ans = dfs(grid,0,0,0);
        if(ans  == INT_MIN){
            return 0;
        }
        return ans;
    }
};