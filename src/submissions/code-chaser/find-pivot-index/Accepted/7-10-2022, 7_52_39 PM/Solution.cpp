// https://leetcode.com/problems/find-pivot-index

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if(!nums.size()) return -1;
        if(nums.size()==1) return 0;
        int sum = 0, leftSum = 0;
        for(auto i : nums)
            sum += i;
        for (int i = 0; i < nums.size(); i++){
            if (leftSum*2 == sum - nums[i])
                return i;
            leftSum += nums[i];
        }
        return -1;
    }
};