# 48. Rotate Image
# https://leetcode.com/problems/rotate-image/

class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        self.reflect(matrix)
        self.transpose(matrix)
        
    def transpose(self, matrix: List[List[int]]) -> None:
        for i in range(1, len(matrix)):
            for j in range(i):
                matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
    
    def reflect(self, matrix: List[List[int]]) -> None:
        i = 0
        j = len(matrix) - 1
        while i < j:
            matrix[i], matrix[j] = matrix[j], matrix[i]
            i += 1
            j -= 1
            