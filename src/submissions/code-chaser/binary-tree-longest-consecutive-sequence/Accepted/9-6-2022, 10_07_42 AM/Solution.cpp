// https://leetcode.com/problems/binary-tree-longest-consecutive-sequence

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
    int nodeHasValue(int expectedValue, TreeNode* node, unordered_map<TreeNode*, bool> &vis) {
        if (node == nullptr)
            return 0;
        if (node -> val != expectedValue)
            return 0;
        vis[node] = 1;
        return 1 + max(nodeHasValue(expectedValue + 1, node -> left, vis), nodeHasValue(expectedValue + 1, node -> right, vis));
    }
public:
    int longestConsecutive(TreeNode* root) {
        if (!root)
            return 0;
        unordered_map<TreeNode*, bool> vis;
        int maxValue = 1;
        stack<TreeNode*> nodes;
        nodes.push(root);
        while (!nodes.empty()) {
            TreeNode* curr = nodes.top();
            nodes.pop();
            if (curr -> right)
                nodes.push(curr -> right);
            if (curr -> left)
                nodes.push(curr -> left);
            if (!vis[curr])
                maxValue = max(maxValue, nodeHasValue(curr -> val, curr, vis));
        }
        return maxValue;
        
    }
};