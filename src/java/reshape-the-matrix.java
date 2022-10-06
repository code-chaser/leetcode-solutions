/*Question:-In MATLAB, there is a handy function called reshape which can reshape an m x n matrix into a new one with a different size r x c keeping its original data.

You are given an m x n matrix mat and two integers r and c representing the number of rows and the number of columns of the wanted reshaped matrix.

The reshaped matrix should be filled with all the elements of the original matrix in the same row-traversing order as they were.

If the reshape operation with given parameters is possible and legal, output the new reshaped matrix; Otherwise, output the original matrix.*/

//Solution//

class Solution {
    
    public void fill(int val,int[][] mat,int r1,int c1){
        int col=mat[0].length;
        int row=mat.length; 
     
        
        mat[r1][c1]=val;     
        
    }
    
    
    public int[][] matrixReshape(int[][] mat, int r, int c) {
        
        int[][] ans=new int[r][c];
        
        int col=mat[0].length;
        int row=mat.length;
        int r1=0,c1=0;
        
        if(r*c!=col*row)
            return mat;
        
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                
               if(r1<r && c1<c)
               {
                   fill(mat[i][j],ans,r1,c1); 
                   c1++;
               }
            else if(r1<r){
                r1++;
                c1=0;
                fill(mat[i][j],ans,r1,c1); 
                c1++;
            }
                
                            
            }
        }
        return ans;
        
    }
}

//Submission link:-https://leetcode.com/submissions/detail/799639910/
