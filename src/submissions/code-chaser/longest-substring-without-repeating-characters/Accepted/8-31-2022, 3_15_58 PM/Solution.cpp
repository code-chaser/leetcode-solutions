// https://leetcode.com/problems/longest-substring-without-repeating-characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> lastOccurrence;
        int maxLength = 0;
        int startIndex = 1;
        int currLength = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (!lastOccurrence[s[i]]) {
                currLength++;
                lastOccurrence[s[i]] = i + 1;
            }
            else {
                if (lastOccurrence[s[i]] >= startIndex) {
                    maxLength = max(maxLength, currLength);
                    startIndex = lastOccurrence[s[i]] + 1;
                    currLength = i - startIndex + 2;
                    lastOccurrence[s[i]] = i + 1;
                }
                else {
                    currLength++;
                    lastOccurrence[s[i]] = i + 1;
                }
            }
        }
        maxLength = max(maxLength, currLength);
        return maxLength;
    }
};
/*
p w w k e w
0 1 2 3 4 5 -> i
1 2 3 4 5 6 -> startIndex

i = 0 {
    lastOccurrence = {} to {('p':1)};
    currLength = 0 to 1;
    startIndex = 1;
}
i = 1 {
    lastOccurrence = {('p':1)} to {('p':1), ('w':2)};
    currLength = 1 to 2;
    startIndex = 1;

}
i = 2 {
    lastOccurrence = {('p':1), ('w':2)} to {('p':1), ('w':3)}
}
*/