class Solution {
    public int maxProfit(int[] prices, int fee) {
        int n = prices.length;
        int [][] dp = new int[n][2];
        for (int[] tempDp : dp) {
            Arrays.fill(tempDp, -1);
        }
        return maxProfit(prices, fee, 0,  false, dp);
    }
    private int maxProfit(final int[] prices, final int fee, int i, boolean isSelling, int[][] dp) {
        
        int j = 0;
        int n = prices.length;
        if (isSelling) {
            j = 1;
        }
        
        if (i >= n) {
            return 0;
        }
        else if (dp[i][j] != -1) {
            return dp[i][j];
        }
        else {
            // donot do any transaction on current date
            int a = maxProfit(prices, fee, i+1, isSelling, dp);
            int b = 0;
            if (isSelling) {
                // sell a stock
                b = maxProfit(prices, fee, i+1, false, dp) + prices[i] - fee;
            }
            else {
                b = maxProfit(prices, fee, i+1, true, dp) - prices[i];
            }
            int ans = Math.max(a, b);
            dp[i][j] = ans;
            return ans;
        }
    }
}
// Submisssion link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/submissions/664871512/