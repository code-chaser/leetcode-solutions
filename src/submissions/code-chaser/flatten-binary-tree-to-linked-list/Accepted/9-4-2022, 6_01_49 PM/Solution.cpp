// https://leetcode.com/problems/flatten-binary-tree-to-linked-list

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
    void flatten(TreeNode* root) {
        TreeNode* last = nullptr;
        TreeNode* curr = root;
        stack<TreeNode*> nodes;
        while (curr || (!nodes.empty())) {
            if (curr) {
                nodes.push(curr);
                last = curr;
                curr = curr -> left;
            }
            else {
                TreeNode* temp = nodes.top() -> right;
                nodes.pop();
                if (temp)
                    curr = last -> left = temp;
            }
        }
        curr = root;
        while (curr) {
            curr -> right = curr -> left;
            curr -> left = nullptr;
            curr = curr -> right;
        }
    }
};