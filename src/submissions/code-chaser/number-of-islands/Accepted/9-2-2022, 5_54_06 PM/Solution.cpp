// https://leetcode.com/problems/number-of-islands

class Solution {
private:
    void dfs(int r, int c, vector<vector<bool>> &vis, vector<vector<char>> &grid) {
        if (r < 0 || r >= grid.size())
            return;
        if (c < 0 || c >= grid[0].size())
            return;
        if (vis[r][c])
            return;
        vis[r][c] = 1;
        if (grid[r][c] == '0')
            return;
        dfs(r-1,c,vis,grid);
        dfs(r,c+1,vis,grid);
        dfs(r+1,c,vis,grid);
        dfs(r,c-1,vis,grid);
        return;
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int numberOfIslands = 0;
        vector<vector<bool>> vis(grid.size(), vector<bool>(grid[0].size()));
        for (int r = 0; r < grid.size(); r++) {
            for (int c = 0; c < grid[0].size(); c++) {
                if (grid[r][c] == '1' && (!vis[r][c])) {
                    numberOfIslands++;
                    dfs(r,c,vis,grid);
                }
            }
        }
        return numberOfIslands;
    }
};