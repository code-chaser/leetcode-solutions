/*Question:-A message containing letters from A-Z can be encoded into numbers using the following mapping:

'A' -> "1"
'B' -> "2"
...
'Z' -> "26"
To decode an encoded message, all the digits must be grouped then mapped back into letters using the reverse of the mapping above (there may be multiple ways). For example, "11106" can be mapped into:

"AAJF" with the grouping (1 1 10 6)
"KJF" with the grouping (11 10 6)
Note that the grouping (1 11 06) is invalid because "06" cannot be mapped into 'F' since "6" is different from "06".

Given a string s containing only digits, return the number of ways to decode it.*/

class Solution {
    public int numDecodings(String s) {
        Map<Integer, Integer> countMap = new HashMap<>();
        return count(s, 0, countMap);
    }
    public int count(String s, int index, Map<Integer, Integer> countMap) {
        if(countMap.containsKey(index)) return countMap.get(index);
        int count = 0;
        if(index < s.length()) {
            int a1 = Integer.parseInt(s.substring(index, index + 1));
            if(a1 < 1 || a1 > 26)  count += 0;
            else  count += count(s, index + 1, countMap);
            
            if(a1 != 0 && index + 1 < s.length()){
                int a2 = Integer.parseInt(s.substring(index, index + 2));
                if(a2 < 1 || a2 > 26)  count += 0;
                else count += count(s, index + 2, countMap);
            }
            countMap.put(index, count);
            return count;
        } else {
            return 1;
        }
    }
}


//submission link:-https://leetcode.com/submissions/detail/812672463/
