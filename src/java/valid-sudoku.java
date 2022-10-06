/*Question:-Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
Note:

A Sudoku board (partially filled) could be valid but is not necessarily solvable.
Only the filled cells need to be validated according to the mentioned rules.*/

//Solution//

class Solution {
    public boolean isValidSudoku(char[][] board) {
	int[] row = new int[board.length];
	int[] col = new int[board.length];
	int[] cube = new int[board.length];
	for(int k = 0; k < 3; k++) {
		for(int i = 0; i < board.length; i++) {
			for(int j = k * 3; j < (k + 1) * 3; j++) {
				if (!Character.isDigit(board[i][j])) {
					continue;
				}
				int c = 1 << (board[i][j] - '0');
				int cubeIndex = k * 3 + i / 3;
				if ((row[i] & c) > 0 || (col[j] & c) > 0 || (cube[cubeIndex] & c) > 0)  {
					return false;
				}
				row[i] |= c;
				col[j] |= c;
				cube[cubeIndex] |= c;
			}
		}
	}
	return true;
}
}

//Submission link:-https://leetcode.com/submissions/detail/800641694/
