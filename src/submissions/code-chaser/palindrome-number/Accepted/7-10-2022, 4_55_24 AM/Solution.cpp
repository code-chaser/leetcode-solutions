// https://leetcode.com/problems/palindrome-number

class Solution {
private:
    int power(int base, int exp){
        int res = 1;
        while(exp){
            if(exp & 1)
                res *= base, exp--;
            else
                base *= base, exp >>= 1;
        }
        return res;
    }
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return 0;
        for(int i = 0; i < log10(x) / 2; i++)
            if(((x/power(10, log10(x)-i))%10) != ((x/power(10, i))%10))
                return 0;
        return 1;
    }
};

/*

ith digit in x digits long numeral (base 10)
(0 based indexing)
digits after ith: x-i-1
digits before ith: i


*/