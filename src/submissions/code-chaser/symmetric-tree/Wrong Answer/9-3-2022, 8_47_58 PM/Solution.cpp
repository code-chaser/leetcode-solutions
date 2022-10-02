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
        TreeNode* curr;
        stack<TreeNode*> nodes;
        
        vector<int> leftTraversal;
        curr = root -> left;
        while (curr || (!nodes.empty())) {
            if (curr) {
                nodes.push(curr);
                curr = curr -> left;
            }
            else {
                leftTraversal.push_back(-1);
                leftTraversal.push_back(nodes.top() -> val);
                curr = nodes.top() -> right;
                nodes.pop();
            }
        }
        
        vector<int> rightTraversal;
        curr = root -> right;
        while (curr || (!nodes.empty())) {
            if (curr) {
                nodes.push(curr);
                curr = curr -> right;
            }
            else {
                rightTraversal.push_back(-1);
                rightTraversal.push_back(nodes.top() -> val);
                curr = nodes.top() -> left;
                nodes.pop();
            }
        }
        
        return leftTraversal == rightTraversal;
    }
};