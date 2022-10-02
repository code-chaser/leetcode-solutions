// https://leetcode.com/problems/symmetric-tree

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
private:
    bool areMirrored(TreeNode* a, TreeNode* b) {
        if ((!a) || (!b)) {
            return ((!a) && (!b));
        }
        if (a -> val != b -> val)
            return false;
        return areMirrored(a -> left, b -> right) && areMirrored(a -> right, b -> left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        return areMirrored(root -> left, root -> right);
    }
};