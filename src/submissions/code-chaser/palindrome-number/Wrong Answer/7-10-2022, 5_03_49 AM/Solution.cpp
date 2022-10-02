// https://leetcode.com/problems/palindrome-number

class Solution {
public:
    bool isPalindrome(int x) {
        int reversed = 0, x_cpy = x;
        while(x_cpy){
            reversed = (reversed * 10) + (x_cpy % 10);
            x_cpy /= 10;
        }
        return reversed == x;
    }
};