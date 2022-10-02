// https://leetcode.com/problems/binary-tree-postorder-traversal

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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> traversal;
        if (!root)
            return traversal;
        stack<pair<TreeNode*, bool>> nodes;
        nodes.push({root, 0});
        TreeNode* curr = root -> left;
        while ((!nodes.empty()) || (curr)) {
            if (curr) {
                nodes.push({curr, 0});
                curr = curr -> left;
            }
            else if (!nodes.top().second) {
                curr = nodes.top().first -> right;
                nodes.top().second = 1;
            }
            else {
                traversal.push_back(nodes.top().first -> val);
                nodes.pop();
            }
        }
        return traversal;
    }
};