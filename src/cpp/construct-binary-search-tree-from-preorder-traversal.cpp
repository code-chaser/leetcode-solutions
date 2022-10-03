// Question: https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/

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
    TreeNode* build_tree(vector<int>& preorder, int l, int r){
        if(l>r)
            return nullptr;
        TreeNode *root = new TreeNode(preorder[l]);
        if(l == r)
            return root;
        
        int ind = l+1;
        while(ind<=r && preorder[ind]<preorder[l])
            ind++;
        
        root->left = build_tree(preorder, l+1, ind-1);
        root->right = build_tree(preorder, ind, r);
        
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return build_tree(preorder, 0, preorder.size()-1);
    }
};