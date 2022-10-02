// https://leetcode.com/problems/mirror-reflection

class Solution {
public:
    int mirrorReflection(int p, int q) {
        int len = p, rem = len % q;
        bool wall = (p / q) & 1; // 0  for left, 1 for right;
        int k = 0;
        while (rem) {
            k++;
            wall = (((p - q + rem) / q) & 1) ^ wall;
            rem = (p - q + rem) % q;
        }
        if (k & 1)
            return 0;
        return wall ? 1 : 2;
    }
};