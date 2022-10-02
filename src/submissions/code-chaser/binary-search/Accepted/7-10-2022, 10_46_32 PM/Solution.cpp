// https://leetcode.com/problems/binary-search

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size();
        while(l < r) {
            int mid = r - 1 - ((r - 1 - l) >> 1);
            if(nums[mid] < target) l = mid + 1;
            else if(nums[mid] == target) return mid;
            else r = mid;
        }
        return -1;
    }
};