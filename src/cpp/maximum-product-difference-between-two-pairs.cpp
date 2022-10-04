
//   Author - Shadowpii

class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int maxdiff=0;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        maxdiff = abs(nums[0]*nums[1] - nums[n-1]*nums[n-2]);
        return maxdiff;
    }
};