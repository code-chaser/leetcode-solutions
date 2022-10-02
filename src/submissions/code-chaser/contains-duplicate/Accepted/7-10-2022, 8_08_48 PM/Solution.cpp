// https://leetcode.com/problems/contains-duplicate

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> s;
        for(auto i : nums)
            s.insert(i);
        return s.size() < nums.size();
    }
};