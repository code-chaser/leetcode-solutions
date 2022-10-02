// https://leetcode.com/problems/trapping-rain-water

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        stack<int> bars;
        bars.push(0);
        int trappedWater = 0;
        for (int i = 1; i < n; i++) {
            if (height[i] <= height[bars.top()]) {
                bars.push(i);
            }
            else {
                int boundedBar = bars.top();
                bars.pop();
                if (!bars.empty())
                    trappedWater += (min(height[i], height[bars.top()]) - height[boundedBar]) * (i - bars.top() - 1), i--;
                else {
                    bars.push(i);
                }
            }
        }
        return trappedWater;
    }
};