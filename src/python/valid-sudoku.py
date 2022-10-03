#https://leetcode.com/problems/valid-sudoku/

class Solution:
    def isValidSudoku(self, board):
        row = {i:set() for i in range(9)}
        col = {i:set() for i in range(9)}
        box = {i:set() for i in range(9)}
        for i in range(9):
            for j in range(9):
                # skip '.'
                if board[i][j] == '.':
                    continue
                # check row
                if board[i][j] in row[i]:
                    return False
                else:
                    row[i].add(board[i][j])
                # check column
                if board[i][j] in col[j]:
                    return False
                else:
                    col[j].add(board[i][j])
                # check box
                if board[i][j] in box[(i//3)*3+(j//3)]:
                    return False
                else:
                    box[(i//3)*3+(j//3)].add(board[i][j])
        return True