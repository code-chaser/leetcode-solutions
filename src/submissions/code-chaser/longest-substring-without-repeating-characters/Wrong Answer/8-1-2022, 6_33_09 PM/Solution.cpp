// https://leetcode.com/problems/longest-substring-without-repeating-characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        map<int, int> vis;
        for (int i = 0, j = 0; (i < s.size()) && (j < s.size()); j++) {
            if (vis[s[j]]) {
                ans = max(ans, j-i);
                i = vis[s[j]];
                vis[s[j]] = j + 1;
            }
            else {
                ans = max(ans, j-i+1);
                vis[s[j]] = j + 1;
            }
        }
        return ans;
    }
};