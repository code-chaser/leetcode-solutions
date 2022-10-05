class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int> ans;
        int startrow=0;
        int startcol=0;
        int endrow=n-1;
        int endcol=m-1;
        int count=0;
        int total=n*m;
        while(count<total){
            for(int i=startcol;i<=endcol && count<total;i++){
                ans.push_back(matrix[startrow][i]);
                cout<<count++;
            }
            startrow++;
            for(int i=startrow;i<=endrow && count<total;i++){
                ans.push_back(matrix[i][endcol]);
                cout<<count++;
            }
            endcol--;
            for(int i=endcol;i>=startcol && count<total;i--){
                ans.push_back(matrix[endrow][i]);
                cout<<count++;
            }
            endrow--;
            for(int i=endrow;i>=startrow && count<total;i--){
                ans.push_back(matrix[i][startcol]);
                cout<<count++;
            }
            startcol++;
        }
        return ans;
    }
};