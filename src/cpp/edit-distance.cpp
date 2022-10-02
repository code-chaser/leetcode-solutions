/*
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
--||author : Mitternachtsmond||-- 
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/
class Solution 
{
public:
    int minDistance(string word1, string word2) {
        int n1=word1.size();
        int n2=word2.size();
        vector<vector<int>>dp(n2+1,vector<int>(n1+1,0));
        // dp[0][0]=0;
        for(int i=1;i<=n1;i++) dp[0][i]=i;
        for(int i=1;i<=n2;i++) dp[i][0]=i;
        for(int i=1;i<=n2;i++){
            for(int j=1;j<=n1;j++){
                if(word2[i-1]==word1[j-1]) dp[i][j]=dp[i-1][j-1];
                else dp[i][j]=min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]))+1;
            }
        }
        // for(int i=0;i<=n2;i++){
        //     for(int j=0;j<=n1;j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }
        return dp[n2][n1];
    }
};
