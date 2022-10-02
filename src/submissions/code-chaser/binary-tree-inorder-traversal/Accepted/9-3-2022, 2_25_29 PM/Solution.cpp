// https://leetcode.com/problems/binary-tree-inorder-traversal

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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> traversal;
        stack<TreeNode*> nodes;
        TreeNode* curr = root;
        while (1) {
            if (curr) {
                nodes.push(curr);
                curr = curr -> left;
            }
            else {
                if (nodes.empty())
                    return traversal;
                TreeNode* node = nodes.top();
                nodes.pop();
                traversal.push_back(node -> val);
                curr = node -> right;
            }
        }
        return traversal;
    }
};