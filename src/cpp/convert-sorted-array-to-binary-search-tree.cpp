/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return func(nums, 0, nums.size()-1);
    }
    TreeNode *func(vector<int>v, int lo, int hi)
    {
        int m;
        if(lo>hi)
            return NULL;
        m=(lo+hi)/2;
        TreeNode *root=new TreeNode(v[m], func(v, lo, m-1), func(v, m+1, hi));
        return root;
    }
};