class Solution {
    
public:
    bool isMatch(string s, string p) {
        
        int n = s.size();
        int m = p.size();
        
        vector<vector<bool>> dp(n+1, vector<bool> (m+1,false)); //vector used for memoization
        //dp[i][j] will store the output (possible/ not possible) for strings of length i and j, considering we take only the first i and j characters of given strings s and p respectively into consideration
        
        // base cases
        dp[0][0] = true;
        for(int j=1; j<=m; j++){
            dp[0][j] = true;
            for(int i=0; i<j; i++){
                if(p[i]!='*') dp[0][j]=false;
            }
        }
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                
                if(s[i-1]==p[j-1] || p[j-1]=='?') dp[i][j] = dp[i-1][j-1];
                else if(p[j-1]=='*'){
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                }
                else dp[i][j] = false;
            }
        }
        
        return dp[n][m];
    }
};