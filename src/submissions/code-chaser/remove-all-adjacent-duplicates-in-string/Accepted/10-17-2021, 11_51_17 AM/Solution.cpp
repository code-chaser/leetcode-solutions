// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string

class Solution {
public:
    string removeDuplicates(string s) {
        for(int i = 1; i < s.size(); i++) {
            if(s[i - 1] == s[i]) {
                s.erase(i - 1, 2);
                i -= 2;
            }
            if(i < 0) i = 0;
        }
        return s;
    }
};