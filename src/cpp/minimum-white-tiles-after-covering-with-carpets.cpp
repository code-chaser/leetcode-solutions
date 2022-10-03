class Solution {
public:
    int minimumWhiteTiles(string s, int x, int L) {
        int n = s.size();
        int dp[n][x+1][2];
        memset(dp,0,sizeof(dp));
        dp[0][0][0]=dp[0][0][1]=(s[0]=='1'?1:0);
        for(int i=1;i<n;i++){
            dp[i][0][0]=dp[i][0][1]=(dp[i-1][0][1] + (s[i]=='1'?1:0));
        }
        for(int i=1;i<=x;i++){
            dp[0][i][1]=0;
            if(s[0]=='1')dp[0][i][0]=1;
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<=x;j++){
                dp[i][j][0]=min(dp[i-1][j][0],dp[i-1][j][1])+(s[i]=='1'?1:0);
                int left = i - L;
                if(left<0)dp[i][j][1]=0;
                else{
                    dp[i][j][1] = min(dp[i-L][j-1][0],dp[i-L][j-1][1]);
                }
            }
        }
        
        return min(dp[n-1][x][0],dp[n-1][x][1]);
    }
};
