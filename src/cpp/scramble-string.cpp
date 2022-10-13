class Solution {
public:
    bool isScramble(string s1, string s2) {
        int len=s1.size();
        bool ans[len][len][len+1];
        for(int k=1;k<=len+1;k++){
            for(int i=0;i+k<=len;i++){
                for(int j=0;j+k<=len;j++){
                    if(k==1){
                        ans[i][j][k]=(s1[i]==s2[j]);
                    }
                    else{
                        for(int q=1;q<k;q++){
                            ans[i][j][k]= (ans[i][j][q] && ans[i+q][j+q][k-q]) || (ans[i+q][j][k-q] && ans[i][j+k-q][q]);
                            if(ans[i][j][k]){
                                break;
                            }
                        }
                    }
                }
            }
        }
        return ans[0][0][len];
    }
};
