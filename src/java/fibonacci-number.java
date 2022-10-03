// Question - The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, such that each number
//  is the sum of the two preceding ones, starting from 0 and 1. That is,
// F(0) = 0, F(1) = 1
// F(n) = F(n - 1) + F(n - 2), for n > 1.
// Given n, calculate F(n).

// Example 1:

// Input: n = 2
// Output: 1
// Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1.

class Solution {
    public int fib(int n) {
        
        //using recursion

        // if (n<=1)
        //     return n;
        // else
        // {
        //     int[] F = new int[n+1];
        //     F[0]=0;
        //     F[1]=1;
        //     for(int i=2;i<=n;i++)
        //         F[i]=F[i-1]+F[i-2];
        //     return F[n];
        // }
        
//         if(n==0 || n==1)    
//             return n;
        
// 			return fib(n-1)+fib(n-2);
        
//using iterative approach
        int a = 0;
        int b = 1;
        if(n < 2){
            return n;
        }
        else{
        int c = 0;
        for(int i=1; i< n; i++){
            c = a + b;
            a = b;
            b = c;
        }
        return c;
        }
    }
}

// Submission - https://leetcode.com/submissions/detail/787301524/