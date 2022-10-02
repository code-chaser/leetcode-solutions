// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> levels;
        queue<TreeNode*> nodes;
        nodes.push(root);
        int levelNumber = 0;
        while (!nodes.empty()) {
            vector<int> level;
            int levelSize = nodes.size();
            while (levelSize--) {
                level.push_back(nodes.front() -> val);
                if (nodes.front() -> left)
                    nodes.push(nodes.front() -> left);
                if (nodes.front() -> right)
                    nodes.push(nodes.front() -> right);
                nodes.pop();
            }
            if (levelNumber & 1) {
                reverse(level.begin(), level.end());
            }
            levels.push_back(level);
            levelNumber++;
        }
        return levels;
    }
};