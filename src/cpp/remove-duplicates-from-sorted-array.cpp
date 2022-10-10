//https://leetcode.com/problems/remove-duplicates-from-sorted-array/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size(), j = 1;
        for(int i = 1; i < n; i++)
        {
            if(nums[i] != nums[i-1])
            {
                nums[j++] = nums[i];
            }
        }
        return j;
    }
};
