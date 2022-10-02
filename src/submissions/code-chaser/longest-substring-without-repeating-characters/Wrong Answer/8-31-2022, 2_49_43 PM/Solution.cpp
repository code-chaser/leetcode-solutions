// https://leetcode.com/problems/longest-substring-without-repeating-characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> lastOccurrence;
        int maxLength = 0;
        int startIndex = 0;
        int currLength = 0;
        for (int i = 0; i < s.size(); i++) {
            if (lastOccurrence.find(s[i]) == lastOccurrence.end()) {
                currLength++;
                lastOccurrence[s[i]] = i;
            }
            else {
                if (lastOccurrence[s[i]] >= startIndex) {
                    maxLength = max(maxLength, currLength);
                    startIndex = lastOccurrence[s[i]] + 1;
                    currLength = startIndex - i + 1;
                    lastOccurrence[s[i]] = i;
                }
                else {
                    currLength++;
                    lastOccurrence[s[i]] = i;
                }
            }
        }
        maxLength = max(maxLength, currLength);
        return maxLength;
    }
};