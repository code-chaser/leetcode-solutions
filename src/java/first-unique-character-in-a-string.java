/*Question:-Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.

 

Example 1:

Input: s = "leetcode"
Output: 0*/


//Solution


class Solution {
    public int firstUniqChar(String s) {
        int result = Integer.MAX_VALUE;
        for(char c = 'a'; c <= 'z'; c++){
            int index = s.indexOf(c);
            if(index != - 1 && index == s.lastIndexOf(c)){
                result = Math.min(result, index);
            }
        }
        return result == Integer.MAX_VALUE ? - 1 : result;
    }
}


//Subbmission link:-https://leetcode.com/submissions/detail/801402377/
