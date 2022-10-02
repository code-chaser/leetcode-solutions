// https://leetcode.com/problems/median-of-two-sorted-arrays

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> combined;
        for (auto i : nums1)
            combined.push_back(i);
        for (auto i : nums2)
            combined.push_back(i);
        sort(combined.begin(), combined.end());
        if(combined.size() & 1)
            return combined[combined.size() / 2];
        double result = (double) combined[combined.size() / 2] + (double) combined[combined.size() / 2 - 1];
        result /= 2;
        return result;
    }
};