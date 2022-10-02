// https://leetcode.com/problems/longest-common-prefix

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        int ch = 0;
        while (ch < min(strs[0].size(), strs[strs.size() - 1].size())) {
            if (strs[0][ch] == strs[strs.size() - 1][ch])
                ch++;
            else
                break;
        }
        return strs[0].substr(0, ch);
    }
};