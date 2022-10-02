// https://leetcode.com/problems/binary-tree-level-order-traversal

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> levels;
        if (!root) {
            return levels;
        }
        queue<TreeNode*> q1;
        q1.push(root);
        while (!q1.empty()) {
            vector<int> level;
            queue<TreeNode*> q2;
            while (!q1.empty()) {
                level.push_back(q1.front() -> val);
                if (q1.front() -> left != nullptr) q2.push(q1.front() -> left);
                if (q1.front() -> right != nullptr) q2.push(q1.front() -> right);
                q1.pop();
            }
            levels.push_back(level);
            q1 = q2;
        }
        return levels;
    }
};