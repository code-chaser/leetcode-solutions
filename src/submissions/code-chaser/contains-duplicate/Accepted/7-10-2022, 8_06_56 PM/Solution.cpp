// https://leetcode.com/problems/contains-duplicate

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, bool> m;
        for(auto i : nums){
            if(m[i])
                return true;
            m[i] = true;
        }
        return false;
    }
};