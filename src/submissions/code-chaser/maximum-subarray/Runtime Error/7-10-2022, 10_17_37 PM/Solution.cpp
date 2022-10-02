// https://leetcode.com/problems/maximum-subarray

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxElement = nums[0];
        for(int i = 1; i < nums.size(); i++)
            maxElement = max(maxElement, nums[i]);
        if(maxElement <= 0) return maxElement;
        vector<int> segments;
        for(int i = 0; i < nums.size();){
            int segSum = 0;
            if(nums[i] <= 0) while((i < nums.size()) && (nums[i] <= 0))
                segSum += nums[i++];
            else while((i < nums.size()) && (nums[i] >= 0))
                segSum += nums[i++];
            if((segments.size() || (segSum > 0)) && ((i < nums.size()) || (segSum > 0))) segments.push_back(segSum);
        }
        
        vector<int> pref = segments;
        for(int i = 1; i < pref.size(); i++)
            pref[i] += pref[i-1];
        maxElement = segments[0];
        for(int i = 1; i < segments.size(); i++)
            maxElement = max(maxElement, segments[i]);
        int maxSum = maxElement;
        for(int i = 0, j = segments.size(); (i < segments.size()) && (j >= 0); i += 2, j -= 2){
            while((i < (segments.size() - 2)) && ((segments[i] + segments[i+1]) <= 0)) i+=2;
            while((j > i) && ((segments[j-1] + segments[j-2]) <= 0)) j-=2;
            if(i >= j) break;
            maxSum = max(maxSum, pref[j-1] - ((i > 0) ? pref[i-1] : 0));
        }
        return maxSum;
    }
};