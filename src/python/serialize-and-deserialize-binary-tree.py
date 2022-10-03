# 297. Serialize and Deserialize Binary Tree
# https://leetcode.com/problems/serialize-and-deserialize-binary-tree/

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Codec:
    
    def serialize(self, root):
        """Encodes a tree to a single string.
        
        :type root: TreeNode
        :rtype: str
        """
        def serializeUtil(root):
            if not root:
                vals.append("None")
                return
            vals.append(str(root.val))
            serializeUtil(root.left)
            serializeUtil(root.right)
        
        vals = []
        serializeUtil(root)
        return " ".join(vals)
            
    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        def deserializeUtil():
            val = next(vals)
            if val == "None":
                return None
            node = TreeNode(int(val))
            node.left = deserializeUtil()
            node.right = deserializeUtil()
            return node
        
        vals = iter(data.split())
        return deserializeUtil()

# Your Codec object will be instantiated and called as such:
# ser = Codec()
# deser = Codec()
# ans = deser.deserialize(ser.serialize(root))
