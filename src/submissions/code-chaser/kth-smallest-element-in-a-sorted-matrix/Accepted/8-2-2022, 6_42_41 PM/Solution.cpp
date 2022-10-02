// https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int> nums;
        int n = matrix.size();
        for (int i = 0; i < min(k, n); i++)
            nums.push_back(matrix[0][i]);
        // nums is a sorted array;
        // we will pick further rows from the matrix one by one upto kth row;
        // and keep merging them in nums array in O(min(k, n)) time;
        for (int i = 1; i < min(k, n); i++) {
            int ptr1 = 0, ptr2 = 0;
            vector<int> temp;
            while ((ptr1 < nums.size()) && (ptr2 < min(k, n))) {
                if (nums[ptr1] < matrix[i][ptr2])
                    temp.push_back(nums[ptr1++]);
                else
                    temp.push_back(matrix[i][ptr2++]);
            }
            while (ptr1 < nums.size())
                temp.push_back(nums[ptr1++]);
            while (ptr2 < matrix[i].size())
                temp.push_back(matrix[i][ptr2++]);
            nums = temp;
        }
        return nums[k-1];
    }
};