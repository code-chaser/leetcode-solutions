// https://leetcode.com/problems/maximum-subarray

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> prefixSum = nums;
        int maxElement = nums[0];
        for(int i = 1; i < nums.size(); i++)
            prefixSum[i] += prefixSum[i-1], maxElement = max(maxElement, nums[i]);
        if(maxElement <= 0) return maxElement;
        int maxSum = maxElement;
        for(int i = 0, j = nums.size(); ;){
            while((i < nums.size()) && (nums[i] <= 0)) i++;
            while((j > 1) && (nums[j-1] <= 0)) j--;
            cout<<"i: "<<i<<" j: "<<j<<"\n";
            if(i >= j) break;
            maxSum = max(maxSum, prefixSum[j-1] - ((i <= 0) ? 0 : prefixSum[i-1]));
            while((i < nums.size()) && (nums[i] >= 0)) i++;
            while((j > 1) && (nums[j-1] >= 0)) j--;
            if(i >= j) break;
        }
        return maxSum;
    }
};