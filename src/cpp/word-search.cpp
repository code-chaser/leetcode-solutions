class Solution {
public:
    bool help(vector<vector<char>>& board,int cl,int i,int j,int &r,int &c,int &l,string &word){
        if(cl==l){
            return true;
        }
        // if(i==r || j==c) return false;
        char z=board[i][j];
        board[i][j]='*';
        
        if(i>0){
            if(word[cl]==board[i-1][j]) {
                if(help(board,cl+1,i-1,j,r,c,l,word)) return true;
            }
        }
        if(j>0){
            if(word[cl]==board[i][j-1]) {
                if(help(board,cl+1,i,j-1,r,c,l,word)) return true;
            }
        }
        if(i+1<r){
            if(word[cl]==board[i+1][j]) {
                if(help(board,cl+1,i+1,j,r,c,l,word)) return true;
            }
        }
        if(j+1<c){
            if(word[cl]==board[i][j+1]) {
                if(help(board,cl+1,i,j+1,r,c,l,word)) return true;
            }
        }
        board[i][j]=z;
        return false;
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        int r=board.size(),c=board[0].size(),l=word.size();
        if(r*c < l) return 0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(word[0]==board[i][j]){
                    if(help(board,1,i,j,r,c,l,word)) return 1;
                }
            }
        }
        return 0;
    }
};
