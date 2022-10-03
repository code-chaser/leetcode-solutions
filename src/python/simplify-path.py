#https://leetcode.com/problems/simplify-path/

class Solution:
    def simplifyPath(self, path):
        stack = []
        for elem in path.split("/"):
            if stack and elem == "..":
                stack.pop()
            elif elem not in [".", "", ".."]:
                stack.append(elem)
                
        return "/" + "/".join(stack)