// https://leetcode.com/problems/next-permutation

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        for (int i = nums.size() - 1; i > 0; i--) {
            if (nums[i] > nums[i - 1]) {
                nums[i] = nums[i - 1] ^ nums[i] ^ (nums[i - 1] = nums[i]);
                return;
            }
        }
        reverse(nums.begin(), nums.end());
        return;
    }
};