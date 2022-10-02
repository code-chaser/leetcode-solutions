// https://leetcode.com/problems/subsets

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums, int index = 0) {
        vector<vector<int>> powerSet;
        if (index == nums.size() - 1) {
            powerSet.push_back({}), powerSet.push_back({nums[index]});
            return powerSet;
        }
        vector<vector<int>> subPowerSet = subsets(nums, index + 1);
        for (auto &i : subPowerSet) {
            powerSet.push_back(i);
            i.push_back(nums[index]);
            powerSet.push_back(i);
        }
        return powerSet;
    }
};