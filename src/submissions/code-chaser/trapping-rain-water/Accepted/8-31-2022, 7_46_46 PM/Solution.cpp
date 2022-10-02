// https://leetcode.com/problems/trapping-rain-water

class Solution {
public:
    int trap(vector<int>& height) {
        int trappedWater = 0;
        int left = 0, right = height.size() - 1;
        int leftMax = 0, rightMax = 0;
        while (left < right) {
            if (height[left] < height[right]) {
                if (height[left] >= leftMax)
                    leftMax = height[left];
                else
                    trappedWater += (leftMax - height[left]);
                left++;
            }
            else {
                if (height[right] >= rightMax)
                    rightMax = height[right];
                else
                    trappedWater += (rightMax - height[right]);
                right--;
            }
        }
        return trappedWater;
    }
};