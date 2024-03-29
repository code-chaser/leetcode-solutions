// Question - Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search 
// target in nums. If target exists, then return its index. Otherwise, return -1.
// You must write an algorithm with O(log n) runtime complexity.

// Example 1:

// Input: nums = [-1,0,3,5,9,12], target = 9
// Output: 4
// Explanation: 9 exists in nums and its index is 4

class Solution {
    public int search(int[] nums, int target) {
        int start = 0;
        int end = nums.length - 1;
        int mid = start + (end - start)/2;
        while (start <= end) {
            if(target > mid) {
                start = mid + 1;
            } else (target < mid) {
                end = mid - 1;
            } 
        }
        return -1;
        
    }
}

// Submission - https://leetcode.com/submissions/detail/790314581/