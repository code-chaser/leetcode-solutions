// https://leetcode.com/problems/make-array-zero-by-subtracting-equal-amounts

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_set<int> s;
        for (auto i : nums)
            if (i)
                s.insert(i);
        return s.size();
    }
};