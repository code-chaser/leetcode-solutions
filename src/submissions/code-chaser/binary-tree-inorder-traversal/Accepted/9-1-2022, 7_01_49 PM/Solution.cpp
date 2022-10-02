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
        if (root == nullptr)
            return traversal;
        stack<TreeNode*> nodes;
        TreeNode* curr = root -> left;
        nodes.push(root);
        while ((curr != nullptr) || (!nodes.empty())) {
            if (curr == nullptr) {
                curr = nodes.top() -> right;
                traversal.push_back(nodes.top() -> val);
                nodes.pop();
                continue;
            }
            nodes.push(curr);
            curr = curr -> left;
        }
        return traversal;
    }
};