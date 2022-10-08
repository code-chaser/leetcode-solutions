class Solution {
    public int minCut(String s) {
        int n = s.length();
        int[][] dp = new int[n][n];
        for (int [] d : dp) {
            Arrays.fill(d, -1);
        }
        return rec (s, 0, n-1, dp);
    }
    private int rec (String s, int i, int j, int[][] dp) {
        if (i >= j) {
            return 0;
        }
        else if (dp[i][j] != -1) {
            return dp[i][j];
        }
        else {
            int ans = j-i+1;
            if (isPal(s, i, j)) {
                ans = 0;
            }
            else {
                for (int k = i; k <j; k++) {
                    if (isPal(s, i, k)) {
                        int b = rec (s, k+1, j, dp);
                        ans = Math.min(ans, b+1);
                    }
                }
            }
            dp[i][j] = ans;
            return ans;
        }
    }
    private boolean isPal (String s, int i, int j) {
        while (i < j) {
            if (s.charAt(i) != s.charAt(j)) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
}
// Submission link: https://leetcode.com/problems/palindrome-partitioning-ii/submissions/737412173/