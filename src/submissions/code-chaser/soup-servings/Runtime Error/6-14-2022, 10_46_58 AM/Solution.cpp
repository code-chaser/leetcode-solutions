// https://leetcode.com/problems/soup-servings

class Solution {
public:
    double aBeforeB(int a, int b, map<pair<int, int>, double> &dp){
        if(dp.find({a, b}) != dp.end()) return dp[{a, b}];
        if(a <= 0 && b <= 0) return dp[{a, b}] = 0;
        if(a <= 0) return dp[{a, b}] = 1;
        if(b <= 0) return dp[{a, b}] = 0;
        return dp[{a, b}] = (aBeforeB(a - 100, b, dp) + aBeforeB(a - 75, b - 25, dp) + aBeforeB(a - 50, b - 50, dp) + aBeforeB(a - 25, b - 75, dp)) / (4.00);
    }
    double simultaneously(int a, int b, map<pair<int, int>, double> &dp){
        if(dp.find({a, b}) != dp.end()) return dp[{a, b}];
        if(a <= 0 && b <= 0) return dp[{a, b}] = 1;
        if(a <= 0 || b <= 0) return dp[{a, b}] = 0;
        return dp[{a, b}] = (simultaneously(a - 100, b, dp) + simultaneously(a - 75, b - 25, dp) + simultaneously(a - 50, b - 50, dp) + simultaneously(a - 25, b - 75, dp)) / (4.00);
    }
    double soupServings(int n) {
        map<pair<int, int>, double> dp1, dp2;
        return aBeforeB(n, n, dp1) + simultaneously(n, n, dp2) / 2;
    }
};