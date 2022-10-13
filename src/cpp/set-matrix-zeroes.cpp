class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> d1(m,-1);
        vector<int> d2(n,-1);
        
        for(int i=0 ; i<m; i++){
            for(int j=0 ; j<n ; j++){
                
                if(matrix[i][j] == 0){
                    d1[i] = 0;
                    d2[j] = 0;
                }
            }
        }
        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                
                if(d1[i] == 0 or d2[j] == 0) matrix[i][j] = 0; 
            }
        }
        return;
    }
};