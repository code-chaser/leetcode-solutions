//https://leetcode.com/problems/binary-tree-cameras/

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
    // first:true -> has camera
    // second:true -> is being monitored
    
    pair<bool,bool> cal(TreeNode* root,int &ans){
        if(!root){
            return {false,true};
        }
        auto l = cal(root->left,ans);
        auto r = cal(root->right,ans);
        bool cam = false, mon = false;
        if(l.first || r.first){
           mon = true;
        }
        if(l.second==false || r.second==false){
            ans++;
            cam = true;
            mon = true;
        }
        return {cam,mon};
    }
    int minCameraCover(TreeNode* root) {
        int ans = 0;
        auto p = cal(root,ans);
        if(p.second == false)   ans++;
        return ans;
    }
};
