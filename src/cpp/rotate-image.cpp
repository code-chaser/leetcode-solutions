class Solution {
public:
    void shift(int &a, int &b, int &c, int &d){
        int temp;
        temp=a;
        a=d;
        d=c;
        c=b;
        b=temp;
    }
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        for(int i=0;i<n/2;i++){
            for(int j=i;j<n-1-i;j++){
                shift(matrix[i][j],matrix[j][n-1-i],matrix[n-1-i][n-1-j],matrix[n-1-j][i]);
            }
        }
    }
};