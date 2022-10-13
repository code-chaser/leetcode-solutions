class Solution {
public:
    bool isMatch(string s, string p) {
        int m=s.length();
        int n=p.length();
        bool** ans=new bool*[m+1];
        for(int i=0;i<m+1;i++){
            ans[i]=new bool[n+1];
        }
        ans[0][0]=true;
        for(int i=1;i<m+1;i++){
            ans[i][0]=false;
        }
        for(int i=0;i<m+1;i++){
            for(int j=1;j<n+1;j++){
                bool firstmatch=false;
                if( m-i<m && (s[m-i]==p[n-j] || p[n-j]=='.')){
                    firstmatch=true;
                }
                if(n-j+1 <n+1 && p[n-j+1]=='*'){
                    ans[i][j]=(firstmatch && ans[i-1][j]) || ans[i][j-2];
                }
                else{
                    ans[i][j]=firstmatch && ans[i-1][j-1];
                }
            }
        }
        return ans[m][n];
    }
};
