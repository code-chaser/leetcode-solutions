// https://leetcode.com/problems/binary-tree-maximum-path-sum

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
    unordered_map<TreeNode*, int> dp;
    int maxPathSumWithRoot(TreeNode* root) {
        if (dp.find(root) != dp.end()) {
            return dp[root];
        }
        if (!root) {
            return dp[root] = 0;
        }
        int leftSubTree = maxPathSumWithRoot(root -> left);
        int rightSubTree = maxPathSumWithRoot(root -> right);
        return dp[root] = (leftSubTree > 0 ? leftSubTree : 0) + (root -> val) + (rightSubTree > 0 ? rightSubTree : 0);
    }
public:
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        stack<TreeNode*> postorder;
        TreeNode* curr = root;
        while ((curr) || (!postorder.empty())) {
            if (curr) {
                postorder.push(curr);
                curr = curr -> left;
            }
            else {
                TreeNode* spotCurr = postorder.top() -> right;
                if (spotCurr) {
                    curr = spotCurr;
                }
                else {
                    spotCurr = postorder.top();
                    postorder.pop();
                    res = max(res, maxPathSumWithRoot(spotCurr));
                    while ((!postorder.empty()) && (spotCurr == postorder.top() -> right)) {
                        spotCurr = postorder.top();
                        postorder.pop();
                        res = max(res, maxPathSumWithRoot(spotCurr));
                    }
                }
            }
        }
        return res;
        
    }
};