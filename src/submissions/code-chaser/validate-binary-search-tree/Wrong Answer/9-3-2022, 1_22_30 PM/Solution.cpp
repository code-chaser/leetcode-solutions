// https://leetcode.com/problems/validate-binary-search-tree

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
    bool isValidBST(TreeNode* root, bool valueGiven = 0, int val = 0, bool lowerLimit = 0) {
        if (root == nullptr)
            return true;
        if (root -> left) {
            if ((root -> left -> val) >= (root -> val))
                return false;
            if (valueGiven)
                if (lowerLimit)
                    if ((root -> left -> val) <= val)
                        return false;
        }
        if (root -> right) {
            if ((root -> right -> val) <= (root -> val))
                return false;
            if (valueGiven)
                if (!lowerLimit)
                    if ((root -> right -> val) >= val)
                        return false;
        }
        return isValidBST(root -> left, 1, root -> val, 0) && isValidBST(root -> right, 1, root -> val, 1);
    }
};