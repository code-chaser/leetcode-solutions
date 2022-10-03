class Solution {
public:
    string helper(TreeNode* root,vector<TreeNode*> &ans, unordered_map<string, int>&m ){
        if(!root)
            return "# ";
        string node=to_string(root->val)+" ";
        node+=helper(root->left, ans,m);
        node+=helper(root->right, ans,m);
        if(m.count(node) && m[node]==1){
            ans.push_back(root);
            m[node]++;
        }
        else if(!m.count(node)){
            m[node]=1;
        }
        return node;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> ans;
        unordered_map<string, int> m;
        helper(root, ans, m);
        return ans;
    }
};
