// Question: https://leetcode.com/problems/search-in-rotated-sorted-array/

class Solution {
public:
    int bin_search(vector<int>& nums, int target, int s, int e){
        while(s<=e){
            int mid = s + (e-s)/2;
            if(nums[mid] == target)
                return mid;
            if(nums[mid]>target)
                e = mid - 1;
            else
                s = mid + 1;
        }
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n-1;
        
        while(l<r){
            int mid = l + (r-l)/2;
            if(nums[mid]>nums[r])
                l = mid+1;
            else
                r = mid;
        }
        
        if(target<=nums[n-1])
            return bin_search(nums, target, l, n-1);
        else
            return bin_search(nums, target, 0, l-1);
    }
};