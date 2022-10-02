// https://leetcode.com/problems/maximum-number-of-groups-entering-a-competition

class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        int n = grades.size(), ans = 0;
        for (int i = 0, j = 1; i < n; j++) {
            ans += ((n - i) >= j);
            i += j;
        }
        return ans;
    }
};