// https://leetcode.com/problems/valid-parentheses

class Solution {
public:
    bool isValid(string s) {
        int record1 = 0, record2 = 0;
        for(int i = 0; i < s.size(); i++) {
            if(record1 < 0 || record2 < 0) return false;
            if(s[i] == '(') record1++;
            if(s[i] == ')') record1--;
            if(s[i] == '{') record2++;
            if(s[i] == '}') record2--;
        }
        return (record1 == 0)&(record2 == 0);
    }
};