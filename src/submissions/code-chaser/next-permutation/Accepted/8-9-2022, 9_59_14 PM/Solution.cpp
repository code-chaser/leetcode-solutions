// https://leetcode.com/problems/next-permutation

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        for (int i = nums.size() - 1; i > 0; i--) {
            if (nums[i] > nums[i - 1]) {
                int posi = i;
                for (int j = i + 1; j < nums.size(); j++) {
                    if (nums[j] < nums[posi] && nums[j] > nums[i - 1]) {
                        posi = j;
                    }
                }
                nums[posi] = nums[posi] ^ nums[i - 1] ^ (nums[i - 1] = nums[posi]);
                sort(nums.begin() + i, nums.end());
                return;
            }
        }
        reverse(nums.begin(), nums.end());
        return;
    }
};