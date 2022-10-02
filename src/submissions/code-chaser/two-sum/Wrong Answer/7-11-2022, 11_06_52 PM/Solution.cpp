// https://leetcode.com/problems/two-sum

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        sort(nums.begin(), nums.end());
        for (auto i = nums.begin(); i != nums.end(); i++) {
            auto j = lower_bound(i, nums.end(), target - *i);
            if ((*j) == (target - *i)) {
                ans.push_back(i - nums.begin());
                ans.push_back(j - nums.begin());
                break;
            }
        }
        return ans;
    }
};