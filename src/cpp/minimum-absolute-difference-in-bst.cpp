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
    int getMinimumDifference(TreeNode* root) {
        int m;
        TreeNode *p;
        m=INT_MAX;
        p=NULL;
        func(root, p, m);
        return m;
    }
    void func(TreeNode *n, TreeNode *(&p), int &m)
    {
        if(!n)
            return;
        func(n->left, p, m);
        if(p)
            m=min(m, abs(p->val-n->val));
        p=n;
        func(n->right, p, m);
    }
};