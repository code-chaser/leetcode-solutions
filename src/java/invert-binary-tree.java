/*Question:-Given the root of a binary tree, invert the tree, and return its root.
Example 1:-
image link:-https://assets.leetcode.com/uploads/2021/03/14/invert1-tree.jpg
Input: root = [4,2,7,1,3,6,9]
Output: [4,7,2,9,6,3,1]

*/

//Solution

class Solution {

public TreeNode invertTree(TreeNode root) {
    
    helper(root);
    return root;
}

private void helper(TreeNode root)
{
    if(root==null)return;
    
    TreeNode temp=root.left;
    root.left=root.right;
    root.right=temp;
    
    helper(root.left);
    helper(root.right);
    
}
}

//Submission link:-https://leetcode.com/submissions/detail/806137566/
