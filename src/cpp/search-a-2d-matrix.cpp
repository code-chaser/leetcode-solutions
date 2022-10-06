class Solution {
public:
    bool bsearch(vector<vector<int>> arr,int line,int n,int target){
        int start,end;
        start=0;
        end=n-1;
        int mid=start+(end-start)/2;
        while(start<=end){
            if(arr[line][mid]==target){
                return 1;
            }
            else if(arr[line][mid]<target){
                start=mid+1;
            }
            else
                end=mid-1;
            mid=start+(end-start)/2;
        }
        return 0;
    }
    int rowsearch(vector<vector<int>> arr, int rows,int target){
        int ans=-1;
        int start=0;
        int end=rows-1;
        int mid=start+(end-start)/2;
        while(start<=end){
            if(arr[mid][0]>target){
                end=mid-1;
            }
            else{
                ans=mid;
                start=mid+1;
            }
            mid=start+(end-start)/2;
        }
        return ans;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows=matrix.size();
        int col=matrix[0].size();
        if(target<matrix[0][0] || target>matrix[rows-1][col-1])
            return 0;
        for(int i=0;i<rows;i++){
            if(matrix[i][0]==target){
                return 1;
            }
        }
        int line=rowsearch(matrix,rows,target);
        return bsearch(matrix,line,col,target);
    }
};