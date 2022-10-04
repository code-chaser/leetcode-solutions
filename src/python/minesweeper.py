def updateBoard(board, click):
	i, j, m, n = *click, len(board), len(board[0])
	def dfs(i, j):
		if board[i][j] == 'E':
			neis = [(x,y) for x, y in ((i-1,j-1),(i-1,j),(i-1,j+1),(i,j-1),(i,j+1),(i+1,j-1),(i+1,j),(i+1,j+1))
						if 0 <= x < m and 0 <= y < n]
			cnt = sum(board[x][y]=='M' for x,y in neis)
			if not cnt: 
				board[i][j] = 'B'
				for x, y in neis: dfs(x,y)
			else: board[i][j] = str(cnt)
	if board[i][j] == 'M': board[i][j] = 'X'
	else: dfs(i,j)
	return board

//By @KrishGaur1354
