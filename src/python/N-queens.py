class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        def isafe(row,col,board,n):
            drow,dcol = row,col
            
            while row >=0 and col >=0:
                if board[row][col] == 'Q': return False
                row-=1
                col-=1
            row ,col = drow,dcol
            while col >=0:
                if board[row][col] == 'Q': return False
                col -=1
                
            row ,col = drow,dcol
            while row < n  and col >=0:
                if board[row][col] == 'Q': return False
                row+=1
                col-=1
            return True
            
        def solve(col,board,n):
            if col == n:
                copy = [''.join(row) for row in board]
                ans.append(copy)
                return
            
            for row in range(n):
                if isafe(row,col,board,n):
                    board[row][col] = 'Q'
                    solve(col+1,board,n)
                    board[row][col] = '.'
            
            
            
        board = [['.']*n for _ in range(n)]
        ans = []
        solve(0,board,n)
        return ans
