// https://leetcode.com/problems/is-subsequence

class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.size() >= t.size())
            return s==t;
        int last = 0;
        for(auto i : s) {
            bool found = false;
            for(int j = last; j < t.size(); j++) if(i == t[j]) {
                found = true;
                last = j + 1;
                break;
            }
            if (!found) return false;
        }
        return true;
    }
};