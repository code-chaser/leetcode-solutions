/*
Question: You are climbing a staircase. It takes n steps to reach the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Example 1:
    Input: n = 2
    Output: 2
    Explanation: There are two ways to climb to the top.
    1. 1 step + 1 step
    2. 2 steps
 */

//Solution
class Solution {
    public int climbStairs(int n) {
        if (n == 1) {
            return 1;
        }
        int a = 1;
        int b = 1;
        int count = 0;
        while (n > 1) {
            count = a + b;
            int temp = b;
            b = count;
            a = temp;
            n--;
        }
        return count;
    }
}

//Submission link: https://leetcode.com/submissions/detail/703917952/
