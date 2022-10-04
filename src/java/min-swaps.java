/*
You are given two integer arrays of the same length nums1 and nums2. In one operation, you are allowed to swap nums1[i] with nums2[i].

For example, if nums1 = [1,2,3,8], and nums2 = [5,6,7,4], you can swap the element at i = 3 to obtain nums1 = [1,2,3,4] and nums2 = [5,6,7,8].
Return the minimum number of needed operations to make nums1 and nums2 strictly increasing. The test cases are generated so that the given input always makes it possible.

An array arr is strictly increasing if and only if arr[0] < arr[1] < arr[2] < ... < arr[arr.length - 1].
*/

class Solution {
    public int minSwap(int[] nums1, int[] nums2) {
        int n = nums1.length;
        
        // initialize dp table
        int[][] memo = new int[2][n];
        Arrays.fill(memo[0], -1);
        Arrays.fill(memo[1], -1);
        memo[0][0] = 0;
        memo[1][0] = 1;
        
        return Math.min(recurse(nums1, nums2, n - 1, 0, memo),
                        recurse(nums1, nums2, n - 1, 1, memo));
    }
    
    private int recurse(int[] nums1, int[] nums2, int i, int swap, int[][] memo) {
        //check dp table
        if (memo[swap][i] != -1)
            return memo[swap][i];
        
        // initial value is set as max
        int res = Integer.MAX_VALUE;
        
        // if array is increasing without swapping
        if (nums1[i] > nums1[i - 1] && nums2[i] > nums2[i - 1])
                res = recurse(nums1, nums2, i - 1, swap, memo);
        
        // if array is increasing with swapping
        if (nums1[i] > nums2[i - 1] && nums2[i] > nums1[i - 1])
                res = Math.min(res, 
                               recurse(nums1, nums2, i - 1, 1 - swap, memo));
        
        memo[swap][i] = swap == 0 ? res : res + 1;
        return memo[swap][i];
    }
}