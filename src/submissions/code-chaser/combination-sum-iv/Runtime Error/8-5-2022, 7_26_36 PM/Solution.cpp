// https://leetcode.com/problems/combination-sum-iv

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<long long> comb(target + 1);
        comb[0] = 1;
        for (long long i = 1; i < comb.size(); i++) {
            for (long long j = 0; j < nums.size(); j++) {
                if (i - nums[j] >= 0) {
                    comb[i] += comb[i - nums[j]];
                }
            }
        }
        return comb[target];
        
    }
};