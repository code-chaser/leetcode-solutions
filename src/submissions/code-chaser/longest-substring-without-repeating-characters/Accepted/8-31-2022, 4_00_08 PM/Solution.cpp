// https://leetcode.com/problems/longest-substring-without-repeating-characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int maxLength = 0;
        unordered_map<char, int> lastOccurrence;
        for (int i = 0, j = 0; i < n; i++) {
            if (lastOccurrence[s[i]] > 0) {
                j = max(lastOccurrence[s[i]], j);
            }
            maxLength = max(maxLength, i - j + 1);
            lastOccurrence[s[i]] = i + 1;
        }
        return maxLength;
    }
};