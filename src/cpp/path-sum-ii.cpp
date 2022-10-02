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
    void f(vector<vector<int>>&ans,vector<int>vec,int targetSum,TreeNode*root){
 if(root==NULL)return;
              vec.push_back(root->val);
       targetSum-=root->val;
        if(root->left==NULL&&root->right==NULL&&targetSum==0){
           
                ans.push_back(vec);
           
                return ;
            }        
            
            
            
            
      
        f(ans,vec,targetSum,root->left);
       
        f(ans,vec,targetSum,root->right);
          vec.pop_back();
        
        
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        vector<int>vec;
        f(ans,vec,targetSum,root);return ans;
    }
};