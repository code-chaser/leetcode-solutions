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
    int rangeSumBST(TreeNode* root, int low, int high) {
        int s;
        s=0;
        func(root, low, high, s);
        return s;
    }
    void func(TreeNode *root, int low, int high, int &s)
    {
        if(!root)
            return;
        if(high<root->val)
        {
            func(root->left, low, high, s);
            return;
        }
        if(low>root->val)
        {
            func(root->right, low, high, s);
            return;
        }
        s+=root->val;
        func(root->left, low, high, s);
        func(root->right, low, high, s);
    }
};