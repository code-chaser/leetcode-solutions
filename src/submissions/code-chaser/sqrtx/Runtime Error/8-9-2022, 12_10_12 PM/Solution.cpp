// https://leetcode.com/problems/sqrtx

class Solution {
public:
    int mySqrt(int x) {
        int ans = 0;
        while (1) {
            if (ans * ans > x)
                return ans - 1;
            ans += 1;
        }
    }
};