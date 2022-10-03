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
    int diameter(TreeNode* root, int &h){
        if(!root){
            h = 0;
            return 0;
        }
        
        int h1 = 0, h2 = 0;
        int d1 = diameter(root->left, h1);
        int d2 = diameter(root->right, h2);
        
        h = max(h1, h2)+1;
        
        return max({d1, d2, h1+h2});
    }
    
    
    int diameterOfBinaryTree(TreeNode* root) {
        int h = 0;
        return diameter(root, h);
    }
};