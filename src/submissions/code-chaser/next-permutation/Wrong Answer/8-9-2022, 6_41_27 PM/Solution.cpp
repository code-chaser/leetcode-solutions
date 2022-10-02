// https://leetcode.com/problems/next-permutation

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        for (int i = nums.size() - 1; i > 0; i--) {
            if (nums[i] > nums[i - 1]) {
                int last = nums[nums.size() - 1];
                for (int j = nums.size() - 1; j >= i; j--) {
                    nums[j] = nums[j - 1];
                }
                nums[i - 1] = last;
                return;
            }
        }
        reverse(nums.begin(), nums.end());
        return;
    }
};