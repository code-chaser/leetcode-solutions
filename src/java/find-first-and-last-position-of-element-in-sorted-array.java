class Solution {
    public int[] searchRange(int[] nums, int target) {
        int a = findFirst(nums, target);
        int b = findLast(nums, target);
        
        int[] x = new int[2];
        x[0] = a;
        x[1] = b;
        return x;
    }
    private int findFirst (int[] nums, int target) {
        int n = nums.length;
        int i = 0;
        int j = n-1;
        
        int ans = -1;
        
        while (i <= j) {
            int m = i + (j-i)/2;
            if (nums[m] == target) {
                ans = m;
                j = m - 1;
            }
            else if (nums[m] > target) {
                j = m-1;
            }
            else {
                i = m+1;
            }
        }
        
        return  ans;
    }
    
    private int findLast (int[] nums, int target) {
        int n = nums.length;
        int i = 0;
        int j = n-1;
        
        int ans = -1;
        
        while (i <= j) {
            int m = i + (j-i)/2;
            if (nums[m] == target) {
                ans = m;
                i = m + 1;
            }
            else if (nums[m] > target) {
                j = m-1;
            }
            else {
                i = m+1;
            }
        }
        
        return  ans;
    }
}
// Submission Link: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/submissions/635553424/