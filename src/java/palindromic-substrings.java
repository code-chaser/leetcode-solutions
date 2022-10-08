class Solution {
    public int countSubstrings(String s) {
        int n = s.length();
        int[][] dp = new int[n][n];
        int ans = 0;
        for (int i= 0; i<n; i++) {
            for (int j = i; j<n; j++) {
                if (isPal(s, i, j, dp)) {
                    ans ++;
                }
            }
        }
        return ans;
    }
    private boolean isPal (String s, int i, int j, int[][] dp) {
        if (i >= j) {
            return true;
        }
        else if (dp[i][j] != 0) {
            return dp[i][j] == 1;
        }
        else {
            boolean ans = false;
            if (s.charAt(i) == s.charAt(j)) {
                ans = isPal(s, i+1, j-1, dp);
            }
            else {
                ans = false;
            }
            
            dp[i][j] = ans ? 1 : -1;
            
            return ans;
        }
    }
}
// submission link: https://leetcode.com/problems/palindromic-substrings/submissions/620740483/