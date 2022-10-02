// https://leetcode.com/problems/two-sum

#include <bits/stdc++.h>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size();i++){
            auto k=lower_bound(nums.begin(),nums.end(),target-nums[i]);
            if (*k==target-nums[i])
                return {i,(int)(k-nums.begin())};
        }
        return {0,1};
    }
};