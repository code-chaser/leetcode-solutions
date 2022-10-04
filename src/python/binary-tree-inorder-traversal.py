#https://leetcode.com/problems/binary-tree-inorder-traversal/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        ans = []
        if root != None:
            ans += self.inorderTraversal(root.left)
            ans.append(root.val)
            ans += self.inorderTraversal(root.right)
        return ans
