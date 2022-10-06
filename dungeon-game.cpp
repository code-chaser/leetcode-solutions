//https://leetcode.com/problems/dungeon-game/

class Solution {
public:
    vector<vector<int>> dp;
    int func(vector<vector<int>>& a,int i,int j){
        if(i == a.size() || j == a[0].size()){
            return INT_MAX;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int temp = min(func(a,i+1,j),func(a,i,j+1));
        temp = temp == INT_MAX ? 1 : temp;
        
        return dp[i][j] = temp - a[i][j] > 0 ? temp - a[i][j] : 1;
        
    }
    
    int calculateMinimumHP(vector<vector<int>>& a) {
        int n = a.size();
        int m = a[0].size();
        dp = vector<vector<int>> (n+1,vector<int>(m+1,-1));
       
        return func(a,0,0);
    }
};