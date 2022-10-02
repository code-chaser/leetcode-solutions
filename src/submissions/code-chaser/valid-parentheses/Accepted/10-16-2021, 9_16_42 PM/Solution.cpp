// https://leetcode.com/problems/valid-parentheses

/*
~~~~~~~~~~~~~~~~~~~~~~~~~~~
--||author : codechaser||-- 
~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/
class Solution {
public:
    bool isValid(string s) {
        stack<char> record;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{') record.push(s[i]);
            else if(record.empty()) return false;
            else if((s[i] != record.top()+1) && (s[i] != record.top()+2)) return false;
            else record.pop();
        }
        return record.empty();
    }
};
/*
    |---------------------------------------------------|
    |||   https://codeforces.com/profile/codechaser   |||
    |||   https://www.codechef.com/users/codechaser   |||
    |||        https://github.com/code-chaser         |||
    |---------------------------------------------------|
*/