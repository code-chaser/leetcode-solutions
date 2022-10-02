// https://leetcode.com/problems/longest-substring-without-repeating-characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> lastOccurrence;
        int maxLength = 0;
        int startIndex = 1;
        int currLength = 0;
        for (int i = 0; i < s.size(); i++) {
            if (!lastOccurrence[s[i]]) {
                currLength++;
                lastOccurrence[s[i]] = i + 1;
            }
            else {
                if (lastOccurrence[s[i]] >= startIndex) {
                    maxLength = max(maxLength, currLength);
                    startIndex = lastOccurrence[s[i]] + 1;
                    currLength = i - startIndex + 1;
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