class Solution {
public:
char arr[1000][1000];
string convert(string s, int numRows) {

    if(numRows==1)return s;
    
    int k=0; //string index
    int j=0; //column
    int i=0; //Row 
    
    //Traverse string till last row when column is not increasing
    while(i<numRows-1 && k<s.size()){
        arr[i][j]=s[k];
        i++;
        k++;
        //When i reaches at last row Move Diagonally in Array and 
        //increase column until i reaches at First row
        if(i==numRows-1){
            //Move Diagonally in Array
            while(i>0 && k<s.size()){
                arr[i][j]=s[k];
                i--;
                j++;
                k++;
            }
        }
    }
    
  //Store character by traversing array
  string res=""; 
  for(int i=0;i<numRows;i++){
      for(int m=0;m<=j;m++){
          if(arr[i][m]!=NULL){
              res+=arr[i][m];
          }
      }
  }
  
    return res;
}
};
// you can check the solution on this link https://leetcode.com/problems/zigzag-conversion/submissions/