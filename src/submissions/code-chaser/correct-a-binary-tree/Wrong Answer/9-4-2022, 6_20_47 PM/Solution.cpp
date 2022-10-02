// https://leetcode.com/problems/correct-a-binary-tree

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
    TreeNode* correctBinaryTree(TreeNode* root) {
        unordered_set<TreeNode*> vis;
        TreeNode* curr = root;
        stack<TreeNode*> nodes;
        while (curr || (!nodes.empty())) {
            if (curr) {
                nodes.push(curr);
                curr = curr -> right;
                if (curr)
                    vis.insert(curr);
            }
            else {
                TreeNode* temp = nodes.top() -> left;
                if (temp) {
                    if (temp -> right) {
                        if (vis.find(temp -> right) != vis.end()) {
                            nodes.top() -> left = nullptr;
                            return root;
                        }
                    }
                    curr = temp;
                }
                nodes.pop();
            }
        }
        return root;
    }
};