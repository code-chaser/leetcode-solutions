class Solution {
public:
    string shortestCommonSupersequence(string s, string t) {
        int n=s.size();
        int m=t.size();
        int dp[n+1][m+1];
        array<int,3>parent[n+1][m+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0||j==0){
                    dp[i][j]=0;
                    parent[i][j]={i,j,0};
                    continue;
                }
                if(s[i-1]==t[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                    parent[i][j]={i-1,j-1,1};
                }
                else{
                    if(dp[i-1][j]>=dp[i][j-1]){
                        dp[i][j]=dp[i-1][j];
                        parent[i][j]={i-1,j,0};
                    }else{
                        dp[i][j]=dp[i][j-1];
                        parent[i][j]={i,j-1,0};
                    }
                }
                
            }
        }
        cout<<dp[n][m]<<endl;
        int x=n,y=m;
        vector<int>a,b;
        while(true){
            int num=parent[x][y][2];
            if(num==1){
                a.push_back(x-1);
                b.push_back(y-1);
            }
            int t1=parent[x][y][0];
            int t2=parent[x][y][1];
            if(x==t1&&y==t2)break;
            x=t1;
            y=t2;
        }
        
        string ans="";
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        
        for(int i=0;i<a.size();i++){
            int x=a[i];
            int y=b[i];
            int start1=0,start2=0;
            if(i!=0)start1=a[i-1]+1;
            if(i!=0)start2=b[i-1]+1;
            for(int j=start1;j<x;j++)ans+=s[j];
            for(int j=start2;j<y;j++)ans+=t[j];
            ans+=s[x];
        }
        //cout<<ans<<endl;
        for(int j=a.back()+1;j<n;j++)ans+=s[j];
        for(int j=b.back()+1;j<m;j++)ans+=t[j];
        return ans;
        
    }
};
