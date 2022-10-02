// https://leetcode.com/problems/next-permutation

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        for (int i = nums.size() - 1; i > 0; i--) {
            if (nums[i] > nums[i - 1]) {
                int j;
                for (j = i + 1; (j < nums.size()) && (nums[j] > nums[i - 1]); j++);
                nums[j - 1] = nums[j - 1] ^ nums[i - 1] ^ (nums[i - 1] = nums[j - 1]);
                reverse(nums.begin() + i, nums.end());
                return;
            }
        }
        reverse(nums.begin(), nums.end());
        return;
    }
};