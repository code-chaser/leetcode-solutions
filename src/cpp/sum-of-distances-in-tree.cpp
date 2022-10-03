class Solution {
public:
    vector<vector<int> >adj;
    vector<int>euler;
    vector<int>dp;
    vector<int>st;
    void dfs(int x,int p){
        dp[x]=0;
        euler.push_back(x);
        for(auto i:adj[x]){
            if(i==p)continue;
            dfs(i,x);
            dp[x]+=dp[i];
            dp[x]+=st[i];
            dp[x]++;
            st[x]+=st[i];
            st[x]++;
            euler.push_back(x);
        }
        
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        adj=vector<vector<int> >(n);
        for(auto p : edges){
            adj[p[0]].push_back(p[1]);
            adj[p[1]].push_back(p[0]);
        }
        dp=vector<int>(n,0);
        st=vector<int>(n,0);
        euler.clear();
        vector<int>ans(n,0);
        dfs(0,0);
       
        ans[0]=dp[0];
        for(int i=1;i<euler.size();i++){
            int x = euler[i-1];
            int y = euler[i];
            dp[x]-=dp[y];
            dp[x]-=st[y];
            dp[x]--;
            st[x]-=st[y];
            st[x]--;
            st[y]+=st[x];
            st[y]++;
            dp[y]+=dp[x];
            dp[y]+=st[x];
            dp[y]++;
            ans[y]=dp[y];
        }
        return ans;
        
    }
};
