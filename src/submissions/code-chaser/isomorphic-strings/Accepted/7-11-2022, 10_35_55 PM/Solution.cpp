// https://leetcode.com/problems/isomorphic-strings

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()) return false;
        vector<int8_t> chars1(128,-1), chars2(128,-1);
        for(int i = 0; i < s.size(); i++){
            if((chars1[s[i]] != t[i]) && (chars1[s[i]] != -1))
                return false;
            chars1[s[i]] = t[i];
            if((chars2[t[i]] != s[i]) && (chars2[t[i]] != -1))
                return false;
            chars2[t[i]] = s[i];
        }
        return true;
    }
};