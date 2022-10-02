// https://leetcode.com/problems/search-insert-position

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size();
        while (l < (r - 1)) {
            int mid = r - ((r + 1 - l) >> 1);
            if (nums[mid] < target) l = mid;
            else if (nums[mid] == target) return mid;
            else r = mid;
        }
        return l + 1;
    }
};