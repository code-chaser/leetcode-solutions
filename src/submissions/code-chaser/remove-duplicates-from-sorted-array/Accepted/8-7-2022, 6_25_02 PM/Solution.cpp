// https://leetcode.com/problems/remove-duplicates-from-sorted-array

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<bool> present(201,0);
        int res = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            if (!present[nums[i] + 100])
                nums[res++] = nums[i];
            present[nums[i] + 100] = 1;
        }
        return res;
    }
};