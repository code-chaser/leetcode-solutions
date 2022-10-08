//https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)  return -1;
        int low = 0;
        int high = n-1;
        
        if(nums[low] <= nums[high]){
            return nums[0];
        }
        
        int pos = -1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(nums[mid]<nums[(mid-1+n)%n] && nums[mid]<nums[(mid+1)%n]){
                pos = mid;  break;
            }
            else if(nums[mid] >= nums[0]){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return nums[pos];
    }
};