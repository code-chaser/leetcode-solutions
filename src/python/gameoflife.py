def gameOfLife(self, board):
    board[:] = [[int(3 in (count, count - live))
                 for j, live in enumerate(row)
                 for count in [sum(sum(row[j-(j>0):j+2])
                                   for row in board[i-(i>0):i+2])]]
                for i, row in enumerate(board)]
    
// By @KrishGaur1354
