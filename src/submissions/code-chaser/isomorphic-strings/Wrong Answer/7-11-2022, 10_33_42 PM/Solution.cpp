// https://leetcode.com/problems/isomorphic-strings

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()) return false;
        vector<int8_t> chars(128,-1);
        for(int i = 0; i < s.size(); i++){
            if((chars[s[i]] != t[i]) && (chars[s[i]] != -1))
                return false;
            chars[s[i]] = t[i];
        }
        return true;
    }
};