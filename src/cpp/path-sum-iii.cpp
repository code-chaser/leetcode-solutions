class Solution {
public:
    void dfs(TreeNode* root, int target, int prev_sum) {
        if (!root) return;
        prev_sum += root->val;
        
        res += prefix[prev_sum - target];
        
        prefix[prev_sum]++;
        
        dfs(root->left, target, prev_sum);
        dfs(root->right, target, prev_sum);
        
        prefix[prev_sum]--;
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        prefix[0]++;
        dfs(root, targetSum, 0);
        return res;
    }
    
private:
    unordered_map<int, int> prefix;
    int res = 0;
};

// By @KrishGaur1354