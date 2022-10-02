// https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int> nums;
        int n = matrix.size();
        for (int row = 0; row < min(k, n); row++)
            for (int cell = 0; cell < min(k, n); cell++)
                nums.push_back(matrix[row][cell]);
        sort(nums.begin(), nums.end());
        return nums[k-1];
    }
};