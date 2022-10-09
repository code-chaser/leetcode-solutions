class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n=nums.size();
        int count =0;
        int left;
        int right;
        for(int mid =1; mid<n-1;mid++){
            left=mid-1;
            right=mid+1;
            while(nums[right]==nums[mid] && right+1<n){
                right++;
            }            
            if(nums[mid]<nums[left] && nums[mid]<nums[right])
                count++;
            if(nums[mid]>nums[left] && nums[mid]>nums[right])
                count++;
        }
    return count;
    }
};