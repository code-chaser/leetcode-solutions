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
    bool findTarget(TreeNode* root, int k) {
        int i, j;
        vector<int>v;
        func(root, v);
        i=0;
        j=v.size()-1;
        while(i<j)
        {
            if((v[i]+v[j])==k)
                return true;
            else if((v[i]+v[j])<k)
                i++;
            else
                j--;
        }
        return false;
    }
    void func(TreeNode *n, vector<int>&v)
    {
        if(!n)
            return;
        func(n->left, v);
        v.push_back(n->val);
        func(n->right, v);
    }
};