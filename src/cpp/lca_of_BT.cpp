/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* ans;
    bool helper(TreeNode* root, TreeNode* p, TreeNode* q){
        if(!root){
            return false;
        }
        bool left = helper(root->left,p,q);
        bool right = helper(root->right,p,q);
        if(left&&right){
            ans = root;
            return false;
        }
        if(root->val==p->val || root->val==q->val){
            if(left || right){
                ans = root;
                return false;
            }
            else {
                return true;
            }
        }
        return left || right;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        ans = NULL;
        helper(root,p,q);
        return ans;
    }
};
