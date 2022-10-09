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
    void recoverTree(TreeNode* root) {
        TreeNode *p, *f, *m, *l;
        p=NULL;
        f=NULL;
        m=NULL;
        l=NULL;
        func(root, p, f, m, l);
        if(l)
            swap(f->val, l->val);
        else
            swap(f->val, m->val);
    }
    void func(TreeNode *n, TreeNode *(&p), TreeNode *(&f), TreeNode *(&m), TreeNode *(&l))
    {
        if(!n)
            return;
        func(n->left, p, f, m, l);
        if(p && n->val<p->val)
        {
            if(!m)
            {
                f=p;
                m=n;
            }
            else
                l=n;
        }
        p=n;
        func(n->right, p, f, m, l);
    }
};