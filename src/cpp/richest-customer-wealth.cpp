
//   Author - Shadowpii

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int m,n,max=0,sum=0;
        m = accounts.size();
        n = accounts[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                sum = sum + accounts[i][j];
                
            }
            if(sum>max){
                    max = sum;
                }
                sum = 0;
        }
        
        return max;
    }
};