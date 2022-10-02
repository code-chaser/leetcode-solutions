// https://leetcode.com/problems/find-pivot-index

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0, leftSum = 0;
        for(auto i : nums)
            sum += i;
        for (int i = 0; i < nums.size(); i++){
            if (i > 0)
                leftSum += nums[i-1];
            if (leftSum*2 == sum - nums[i])
                return i;
        }
        return -1;
    }
};