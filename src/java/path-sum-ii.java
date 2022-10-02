// Question - https://leetcode.com/problems/path-sum-ii/

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
    
    List<List<Integer>> list;
    
    public List<List<Integer>> pathSum(TreeNode root, int targetSum) {
        
        if (root==null) {
            return new ArrayList<>();
        }
        
        list=new ArrayList<>();
        path(root,targetSum,0,new ArrayList<>());
        
        return list;
    }
    
    void path(TreeNode root, int target, int sum, List<Integer> list1) {
        
        if (root==null) {
            return;
        }
        
        list1.add(root.val);
        
        sum=sum+root.val;
        
        if (root.left==null && root.right==null && sum==target) {
            
            List<Integer> ans=new ArrayList(list1);
            list.add(ans);
        }
        
        path(root.left,target,sum,list1);
        path(root.right,target,sum,list1);
        
        list1.remove(list1.size()-1);
    }
}

// Submission - https://leetcode.com/submissions/detail/807289901/
