// Question - https://leetcode.com/problems/path-sum-iii/

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public int pathSum(TreeNode root, int targetSum) {
        return count(root,targetSum,0,false);
    }
    
    private int count(TreeNode root, int targetSum, int sum, boolean flag) {
        
        if (root==null) {
            return 0;
        }
        
        int cnt=0;
        
        cnt=cnt+count(root.left,targetSum,sum+root.val,true) + count(root.right,targetSum,sum+root.val,true);
        
        if (!flag) {
            cnt+= count(root.left,targetSum,sum,false) + count(root.right,targetSum,sum,false);
        }
        
        if (root.val+sum==targetSum) {
            cnt++;
        }
        
        return cnt;
    }
}

// Submission - https://leetcode.com/submissions/detail/572580737/