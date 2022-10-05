class Solution {
    public int[] twoSum(int[] nums, int target) {
        int numsSize = nums.length - 1;
        int[] results = null;
        for (int i = 0; i <= numsSize; i++) {
            for(int j = i+1; j <= numsSize; j++) {
                if (nums[i]+nums[j] == target) {
                    results = new int[]{i, j};
                }
            }
        }
        return results;
    }
}