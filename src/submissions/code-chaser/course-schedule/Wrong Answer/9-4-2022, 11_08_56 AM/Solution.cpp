// https://leetcode.com/problems/course-schedule

class Solution {
    bool cycle(int curr, int numCourses, vector<vector<int>>& prerequisites, vector<bool>& vis, vector<bool>& currVis) {
        if (currVis[curr])
            return true;
        vis[curr] = currVis[curr] = 1;
        for (int prerequisite : prerequisites[curr]) {
            vector<bool> currCurrVis = currVis;
            if (cycle(prerequisite, numCourses, prerequisites, vis, currVis)) {
                return true;
            }
        }
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> dependencies(numCourses);
        for (vector<int> i : prerequisites) {
            dependencies[i[0]].push_back(i[1]);
        }
        vector<bool> vis(numCourses, false);
        for (int i = 0; i < numCourses; i++) {
            if (!vis[i]) {
                vector<bool> currVis(numCourses, false);
                if (cycle(i, numCourses, dependencies, vis, currVis))
                    return false;
            }
        }
        return true;
    }
};