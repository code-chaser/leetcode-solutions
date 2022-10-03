def countSubIslands(self, B, A):
        n, m = len(A), len(A[0])

        def dfs(i, j):
            if not (0 <= i < n and 0 <= j < m and A[i][j] == 1): return 1
            A[i][j] = 0
            res = B[i][j]
            for di, dj in [[0, 1], [1, 0], [-1, 0], [0, -1]]:
                res &= dfs(i + di, j + dj)
            return res
            
        return sum(dfs(i, j) for i in xrange(n) for j in xrange(m) if A[i][j])
      
      //By @KrishGaur1354
