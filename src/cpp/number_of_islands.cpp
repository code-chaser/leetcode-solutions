class Solution {
public:
    int mem;
    void dfs(int x,int y,vector<vector<char>>& grid){
        if(x<0 || y<0 || x>=grid.size() || y>=grid[0].size())
            return;
        if(grid[x][y]!='1' || grid[x][y]=='2')return;
        grid[x][y]='2';
        mem++;
        dfs(x+1,y,grid);
        dfs(x,y+1,grid);
        dfs(x-1,y,grid);
        dfs(x,y-1,grid);
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    ans++;mem=0;
                    dfs(i,j,grid);
                    // cout<<mem<<"\n";
                }
            }
        }
        return ans;
    }
};
