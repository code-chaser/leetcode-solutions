// https://leetcode.com/problems/trapping-rain-water

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> maxPref(n, height[0]), maxSuff(n, height[n - 1]);
        for (int i = 1; i < n; i++) {
            maxPref[i] = max(maxPref[i - 1], height[i]);
        }
        for (int i = n - 2; i >= 0; i--) {
            maxSuff[i] = max(maxSuff[i + 1], height[i]);
        }
        int trappedWater = 0;
        for (int i = 0; i < n; i++) {
            trappedWater += max(0, min(maxPref[i], maxSuff[i]) - height[i]);
        }
        return trappedWater;
    }
};