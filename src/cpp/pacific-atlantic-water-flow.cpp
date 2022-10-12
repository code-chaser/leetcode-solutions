class Solution {
public:
    vector <int> dx = {1, -1, 0, 0};
    vector <int> dy = {0, 0, 1, -1};

    bool isValid(vector<vector<int>>& heights, vector<vector<int>>& vis, int x, int y, int curr) {
        if (x >= heights.size() || y >= heights[0].size() || x < 0 || y < 0) {
            return false;
        }
        if (vis[x][y])return false;
        if (heights[x][y] < curr)return false;
        return true;
    }

    void dfs(vector<vector<int>>& vis, vector<vector<int>>& heights, int x, int y) {
        vis[x][y] = 1;
        for (int k = 0; k < 4; k++) {
            if (isValid(heights, vis, x + dx[k], y + dy[k], heights[x][y])) {
                dfs(vis, heights, x + dx[k], y + dy[k]);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        vector<vector<int>> res;

        vector<vector<int>> vispacific(heights.size(), vector<int>(heights[0].size(), 0));
        vector<vector<int>> visatlantic(heights.size(), vector<int>(heights[0].size(), 0));

        // from each pacific edge

        for (int j = 0; j < heights[0].size(); j++) {
            if (!vispacific[0][j]) dfs(vispacific, heights, 0, j);
        }

        for (int i = 1; i < heights.size(); i++) {
            if (!vispacific[i][0]) dfs(vispacific, heights, i, 0);
        }

        // from each atlantic edge

        for (int i = 0; i < heights.size(); i++) {
            if (!visatlantic[i][heights[0].size() - 1]) dfs(visatlantic, heights, i, heights[0].size() - 1);
        }

        for (int j = 0; j < heights[0].size() - 1; j++) {
            if (!visatlantic[heights.size() - 1][j]) dfs(visatlantic, heights, heights.size() - 1, j);
        }


        for (int i = 0; i < heights.size(); i++) {
            for (int j = 0; j < heights[0].size(); j++) {
                if (vispacific[i][j] && visatlantic[i][j]) {
                    res.push_back({i, j});
                }
            }
        }

        return res;
    }
};
