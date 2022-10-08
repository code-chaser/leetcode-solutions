/*Question:-Given a string s, find the length of the longest substring without repeating characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.*/

//Solution

import java.util.*;
class Solution {
    public int lengthOfLongestSubstring(String s) {
        int left = 0;
        int right = 0;
        int length = s.length();
        int max_length = 0;
        Set<Character> check = new HashSet<>();
        
        while(right < length){
            if(check.contains( s.charAt(right)) == true){
                
                while((left < right) && check.contains(s.charAt(right)) == true){
                    check.remove(s.charAt(left));
                    left++;
                }
            }
            
            check.add(s.charAt(right));
            max_length = Math.max(max_length, right-left+1);
            right++;
            
        }
        
        return max_length;
    }
}

//Submission link:-https://leetcode.com/submissions/detail/797209410/
