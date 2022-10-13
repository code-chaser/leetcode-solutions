// Recursive memoized DP

class Solution {
public:
    int solve(vector<int> &A, int B);
    int recur(vector<int>& prices, int ind, int buy, int k, vector<vector<vector<int>>>& dp) {
        if (ind == prices.size())return 0;
        if (k == 0)return 0;
        if (dp[ind][buy][k] != -1)return dp[ind][buy][k];
        if (buy) {
            return dp[ind][buy][k] = max(-prices[ind] + recur(prices, ind + 1, 0, k, dp), recur(prices, ind + 1, 1, k, dp));
        }
        return dp[ind][buy][k] = max(prices[ind] + recur(prices, ind + 1, 1, k - 1, dp), recur(prices, ind + 1, 0, k, dp));
    }

    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(2, vector<int>(k + 1, -1)));
        return recur(prices, 0, 1, k, dp);
    }
};

// Most optimised solution
// Iterative DP + space optimisation

int Solution::solve(vector<int> &A, int B) {
    if (B > A.size() / 2) {
        // infinite transactions case
        int res = 0;
        for (int i = 1; i < A.size(); i++) {
            res += max(0, A[i] - A[i - 1]);
        }
        return res;
    }

    vector <vector<int>> curr(2, vector<int>(B + 1, 0));
    vector <vector<int>> after(2, vector<int>(B + 1, 0));

    for (int i = A.size() - 1; i >= 0; i--) {
        for (int buy = 0; buy <= 1; buy++) {
            for (int b = 1; b <= B; b++) {
                if (buy) {
                    curr[buy][b] = max(-A[i] + after[0][b], after[1][b]);
                }
                else curr[buy][b] = max(A[i] + after[1][b - 1], after[0][b]);
            }
        }
        after = curr;
    }
    return curr[1][B];
}
