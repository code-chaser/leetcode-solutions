// https://leetcode.com/problems/longest-cycle-in-a-graph

class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size(), ans = -1;
        vector<bool> vis(n, 0);
        for (int i = 0; i < n; i++) if (!vis[i]) {
            vector<int> dist(n, 0);
            int k = 0, curr = i;
            while (1) {
                if (vis[curr]) {
                    ans = max(ans, k - dist[curr]);
                    break;
                }
                dist[curr] = k++;
                vis[curr] = 1;
                curr = edges[curr];
                if (curr == -1)
                    break;
            }
        }
        return ans;
    }
};