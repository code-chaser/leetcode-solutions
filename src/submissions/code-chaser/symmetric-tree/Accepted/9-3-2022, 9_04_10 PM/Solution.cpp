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
public:
    bool isSymmetric(TreeNode* root) {
        stack<TreeNode*> s;
        s.push(root -> left);
        s.push(root -> right);
        while (!s.empty()) {
            TreeNode* right = s.top();
            s.pop();
            TreeNode* left = s.top();
            s.pop();
            if ((!right) && (!left))
                continue;
            if ((!right) || (!left))
                return false;
            if (right -> val != left -> val)
                return false;
            s.push(right -> left);
            s.push(left -> right);
            s.push(left -> left);
            s.push(right -> right);
        }
        return true;
    }
};