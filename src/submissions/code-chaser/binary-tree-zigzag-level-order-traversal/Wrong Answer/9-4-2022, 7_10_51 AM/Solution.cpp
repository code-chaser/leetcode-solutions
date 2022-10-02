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
        deque<TreeNode*> nodes;
        if (root) nodes.push_back(root);
        int levelNumber = 0;
        while (!nodes.empty()) {
            vector<int> level;
            int levelSize = nodes.size();
            while (levelSize--) {
                if (levelSize & 1) {
                    level.push_back(nodes.front() -> val);
                    if (nodes.front() -> right)
                        nodes.push_back(nodes.front() -> right);
                    if (nodes.front() -> left)
                        nodes.push_back(nodes.front() -> left);
                    nodes.pop_front();
                }
                else {
                    level.push_back(nodes.back() -> val);
                    if (nodes.back() -> left)
                        nodes.push_front(nodes.back() -> left);
                    if (nodes.back() -> right)
                        nodes.push_front(nodes.back() -> right);
                    nodes.pop_back();
                }
            }
            levels.push_back(level);
            levelNumber++;
        }
        return levels;
    }
};