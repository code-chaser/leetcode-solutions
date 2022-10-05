//https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/

class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int n = nums.size();
        if(k >= n){
            return accumulate(nums.begin(),nums.end(),0);
        }
        int sum = accumulate(nums.begin(),nums.end(),0);
        int win = n-k;
        int minsum = INT_MAX, csum = 0;
        int i=0, j=0;
        while(j<n){
            csum += nums[j];
            if(j-i+1 == win){
                minsum = min(csum,minsum);
                csum -= nums[i];
                i++;
            }
            j++;
        }
        return sum - minsum;
    }
};