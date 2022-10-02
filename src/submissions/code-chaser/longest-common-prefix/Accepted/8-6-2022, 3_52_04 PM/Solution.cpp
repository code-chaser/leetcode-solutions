// https://leetcode.com/problems/longest-common-prefix

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res="";
        for (int ch = 0; ; ch++) {
            for (auto i : strs) {
                if (ch >= i.size())
                    return res;
                if (i[ch] != strs[0][ch])
                    return res;
            }
            res.push_back(strs[0][ch]);
        }
        return res;
    }
};