// https://leetcode.com/problems/valid-parentheses

class Solution {
public:
    bool isValid(string s) {
        stack<char> record;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{') record.push(s[i]);
            else if(record.empty()) return false;
            else if(record.top()+1 != s[i]) return false;
        }
        return true;
    }
};