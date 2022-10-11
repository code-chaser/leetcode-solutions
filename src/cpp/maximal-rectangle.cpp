class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        stack<int>s;
        int n=arr.size();
        vector<int> rl(n);
        rl[n-1]=n;
        s.push(n-1);
        for(int i=n-2;i>=0;i--){
            while(!s.empty() && arr[s.top()]>=arr[i]){
                s.pop();
            }
            if(s.empty()){
                rl[i]=n;
            }
            else{
                rl[i]=s.top();
            }
            s.push(i);
        }
        stack<int>s1;
        vector<int> ll(n);
        ll[0]=-1;
        s1.push(0);
        for(int i=1;i<n;i++){
            while(!s1.empty() && arr[s1.top()]>=arr[i]){
                s1.pop();
            }
            if(s1.empty()){
                ll[i]=-1;
            }
            else{
                ll[i]=s1.top();
            }
            s1.push(i);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans, (rl[i]-ll[i]-1)*arr[i]);
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& arr) {
        int m=arr.size();
        if(m==0){
            return 0;
        }
        int n=arr[0].size();
        if(n==0){
            return 0;
        }
        vector<vector<int>> ans(m,vector<int>(n,0));
        int maximal=0;
        for(int i=0;i<n;i++){
            ans[0][i]=arr[0][i]-'0';
        }
        maximal=max(maximal,largestRectangleArea(ans[0]));
        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){
                if(arr[i][j]=='0'){
                    ans[i][j]=0;
                }
                else{
                    ans[i][j]=ans[i-1][j]+1;
                }
            }
            maximal=max(maximal,largestRectangleArea(ans[i]));
        }
        return maximal;
    }
};
