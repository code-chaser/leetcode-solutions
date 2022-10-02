// https://leetcode.com/problems/contains-duplicate

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, bool> m;
        for(auto i : nums)
            m[i] = true;
        return m.size() < nums.size();
    }
};