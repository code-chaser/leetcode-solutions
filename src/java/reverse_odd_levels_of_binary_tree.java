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
    public TreeNode reverseOddLevels(TreeNode root) {
        Queue<TreeNode> curr = new LinkedList<>();
        
        ArrayList<ArrayList<TreeNode>> levels = new ArrayList<>();
        int level = 0;
        
        curr.add(root);
        
        while (! curr.isEmpty()) {
            int n = curr.size();
            
            levels.add(new ArrayList<>());
            List<TreeNode> nodes = new  ArrayList<>();
            
            for (int i = 0; i<n; i++) {
                
                TreeNode node = curr.poll();
                levels.get(level).add(node);
                nodes.add(node);
                
                if (node != null) {
                    curr.add(node.left);
                    curr.add(node.right);
                }
            }
            level++;
        }
        // for (int i = 0; i<levels.size(); i++) {
        //     String s = "";
        //     for (TreeNode n: levels.get(i)) {
        //         s += (n != null ? n.val:-1) +" ";
        //     }
        //     System.out.println(s);
        // }
        for (int i = 0; i<levels.size(); i++) {
            if (i%2 == 1) {
                
                int a = 0;
                int b = levels.get(i).size() - 1;
                
                while (a < b) {
                    try {
                        int x = levels.get(i).get(a).val;
                        int y = levels.get(i).get(b).val;

                        levels.get(i).get(a).val = y;
                        levels.get(i).get(b).val = x;
                        // System.out.println("A");
                    }
                    catch (Exception e) {
                        
                    }
                    
                    a++;
                    b--;
                    
                }
                
            }
        }
        
        
        return root;
        
    }
    
}
// Submission Link: https://leetcode.com/problems/reverse-odd-levels-of-binary-tree/submissions/802550130/