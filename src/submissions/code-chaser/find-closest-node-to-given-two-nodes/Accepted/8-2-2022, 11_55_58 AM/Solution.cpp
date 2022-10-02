// https://leetcode.com/problems/find-closest-node-to-given-two-nodes

class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        if (node1 == node2)
            return node1;
        int n = edges.size();
        vector<int> rd1(n, -1), rd2(n, -1);
        vector<bool> vis1(n, 0), vis2(n, 0);
        int dist = 0;
        while (!vis1[node1]) {
            vis1[node1] = 1;
            rd1[node1] = dist++;
            node1 = edges[node1];
            if (node1 == -1)
                break;
        }
        dist = 0;
        while (!vis2[node2]) {
            vis2[node2] = 1;
            rd2[node2] = dist++;
            node2 = edges[node2];
            if (node2==-1)
                break;
        }
        vector<pair<int, int>> distances(n, {-1, -1});
        for (int i = 0; i < n; i++) {
            if ((rd1[i] != -1) && (rd2[i] != -1))
                distances[i].first = max(rd1[i], rd2[i]);
            distances[i].second = i;
        }
        sort(distances.begin(), distances.end());
        int ind = 0;
        for (ind = 0; (ind < n) && (distances[ind].first == -1); ind++);
        return (ind < n)?distances[ind].second:(-1);
    }
};