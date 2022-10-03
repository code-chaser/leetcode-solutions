//https://leetcode.com/problems/binary-tree-maximum-path-sum/

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
    int ans = 0;
    int sum(TreeNode* root){
        if(!root){
            return 0;
        }
        if(!root->left && !root->right){
            ans = max(ans,root->val);
            return root->val;
        }
        int l = sum(root->left);
        int r = sum(root->right);
        int ret = max(l+root->val,r+root->val);
        ans = max(ans,max(max(ret,root->val),l+r+root->val));
        return max(ret,root->val);
    }
    int maxPathSum(TreeNode* root) {
        if(!root)   return 0;
        ans = INT_MIN;
        sum(root);
        return ans;
    }
};