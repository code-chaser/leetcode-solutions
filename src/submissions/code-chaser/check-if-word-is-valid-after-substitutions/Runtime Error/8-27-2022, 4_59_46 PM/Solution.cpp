// https://leetcode.com/problems/check-if-word-is-valid-after-substitutions

class Solution {
public:
    bool isValid(string s) {
        stack<char> t;
        for (char i : s) {
            if (i == 'a') {
                t.push(i);
            }
            else if (i == 'b') {
                if (t.top() != 'a')
                    return false;
                t.push(i);
            }
            else if (i == 'c') {
                if (t.top() != 'b')
                    return false;
                t.pop();
                t.pop();
            }
        }
        return t.empty();
    }

};

/*
abcabc ababcc


*/