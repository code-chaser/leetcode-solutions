// https://leetcode.com/problems/subsets

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int k = (1 << n) - 1;
        vector<vector<int>> powerSet;
        while (k >= 0) {
            vector<int> element;
            for (int bitIndex = 0; bitIndex < n; bitIndex++) {
                if (k & (1 << bitIndex)) {
                    element.push_back(nums[bitIndex]);
                }
            }
            powerSet.push_back(element);
            k -= 1;
        }
        return powerSet;
    }
};