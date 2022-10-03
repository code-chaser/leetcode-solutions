//Question: https://leetcode.com/problems/bitwise-and-of-numbers-range/

class Solution {
public:
    //using bitmanipulation
    int rangeBitwiseAnd(int left, int right) {
        int ans = 0;
        while(left<right){
            left >>= 1;
            right >>= 1;
            ans++;
        }
        
        return right<<ans;
    }
};