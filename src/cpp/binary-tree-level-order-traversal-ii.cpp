// Question - https://leetcode.com/problems/binary-tree-level-order-traversal-ii/ 

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
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        vector<int> add;
        if(!root)
            return ans;
        
        queue<TreeNode*> mq;
        mq.push(root);

        while(mq.size() > 0){
            int count = mq.size();
            for(int i = 0; i < count; i++){
                root = mq.front();
                mq.pop();
                add.push_back(root->val);

                if(root->left != NULL)
                    mq.push(root->left);

                if(root->right != NULL)
                    mq.push(root->right);
                }
                ans.push_back(add);
                add.clear();
            }
    
        return ans;
    }
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans = levelOrder(root);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

// Submission - https://leetcode.com/submissions/detail/706141462/
