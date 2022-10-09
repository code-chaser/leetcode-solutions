/*Question:-Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

 */

//Solution

class Solution {

	boolean search(char[][] board, char[] chars, int c, int i, int j, boolean[][] visited) {

		int p = board.length;
		int q = board[0].length;

		int numChars = chars.length;

		// Index out of bounds or current char on board is not equal to char at c
		if(c > numChars - 1 || board[i][j] != chars[c]) {
			return false;
		}

		// The destination has been reached
		if(c == numChars - 1 && board[i][j] == chars[c] && !visited[i][j]) {
			return true;
		} 

		boolean res = false;

		int n = i > 0 ? i - 1 : 0;
		int w = j > 0 ? j - 1 : 0;
		int s = i < p - 1 ? i + 1 : p - 1;
		int e = j < q - 1 ? j + 1 : q - 1;

		// Search for next potential candidate location
		if(!visited[i][j]) {
			visited[i][j] = true;
			res = res || search(board, chars, c + 1, n, j, visited);
			res = res || search(board, chars, c + 1, i, w, visited);
			res = res || search(board, chars, c + 1, s, j, visited);
			res = res || search(board, chars, c + 1, i, e, visited);
			visited[i][j] = false;
		}

		return res;
	}

	public boolean exist(char[][] board, String word) {

		int p = board.length;
		int q = board[0].length;

		boolean[][] visited = new boolean[p][q];
		char[] chars = word.toCharArray();

		boolean res = false;

		// Compute if word is in board
		for(int i = 0; i < p; ++i) {
			for(int j = 0; j < q; ++j) {
				res = res || search(board, chars, 0, i, j, visited);
			}
		}

		return res;
	}
}

//Submission link:-https://leetcode.com/submissions/detail/797204452/
