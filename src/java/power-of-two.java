// question - Given an integer n, return true if it is a power of two. Otherwise, return false.
// An integer n is a power of two, if there exists an integer x such that n == 2x.

// Example 1:
// Input: n = 1
// Output: true
// Explanation: 2^0 = 1

class Solution {
    public boolean isPowerOfTwo(int n) {
        
        if(n == 1){
            return true;
        }else if(n == 0){
            return false;
        }else if(n % 2 != 0){
            return false;
        }
        return isPowerOfTwo(n/2);
        
        
    }
}

// Submission - https://leetcode.com/submissions/detail/789071171/