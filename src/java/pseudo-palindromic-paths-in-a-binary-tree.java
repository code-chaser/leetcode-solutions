/*Question:-Given a binary tree where node values are digits from 1 to 9. A path in the binary tree is said to be pseudo-palindromic if at least one permutation of the node values in the path is a palindrome.

Return the number of pseudo-palindromic paths going from the root node to leaf nodes.
Example 1
image link:-https://assets.leetcode.com/uploads/2020/05/06/palindromic_paths_1.png
Input: root = [2,3,1,3,1,null,1]
Output: 2 
*/

//Solution

class Solution {
    int ans = 0;
    public int pseudoPalindromicPaths (TreeNode root) {
        ans = 0;
        dfs(root, 0);
        return ans;
    }
    private void dfs(TreeNode root, int count) {
        if (root == null) return;
        count ^= 1 << (root.val - 1);
        dfs(root.left, count);
        dfs(root.right, count);
        if (root.left == null && root.right ==  null && (count & (count - 1)) == 0) ans++;
    }
}

//Submission link:-https://leetcode.com/submissions/detail/799637669/
