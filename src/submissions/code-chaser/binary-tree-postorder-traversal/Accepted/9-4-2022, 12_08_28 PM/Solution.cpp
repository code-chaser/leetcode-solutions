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
        stack<TreeNode*> nodes;
        nodes.push(root);
        TreeNode* curr = root -> left;
        while ((curr) || (!nodes.empty())) {
            if (curr) {
                nodes.push(curr);
                curr = curr -> left;
            }
            else {
                TreeNode* temp = nodes.top() -> right;
                if (temp) {
                    curr = temp;
                }
                else {
                    temp = nodes.top();
                    nodes.pop();
                    traversal.push_back(temp -> val);
                    while ((!nodes.empty()) && (temp == nodes.top() -> right)) {
                        temp = nodes.top();
                        nodes.pop();
                        traversal.push_back(temp -> val);
                    }
                }
            }
        }
        return traversal;
    }
};
/*
curr = null;
nodes = [1];
curr = 2;

curr = 2;
nodes = [1,2];
curr = 3;

curr = 3;
nodes = [1,2,3];
curr = null;

curr = null;
nodes = [1,2,3];
temp = null;
    temp = 3;
    traversal = [3];
    nodes = [1,2];

curr = null;
nodes = [1,2];
temp = null;
    temp = 2;
    traversal = [3,2];
    node = [1];
    

*/