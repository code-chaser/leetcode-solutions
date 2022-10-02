// https://leetcode.com/problems/sqrtx

class Solution {
public:
    int mySqrt(int x) {
        long long y = x;
        long long ans = 0;
        while (1) {
            if (ans * ans > y)
                return ans - 1;
            ans += 1;
        }
    }
};