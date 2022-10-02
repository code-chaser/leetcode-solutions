// https://leetcode.com/problems/remove-k-digits

class Solution {
public:
    string removeKdigits(string s, int k) {
        stack<char> result;
        result.push(s[0]);
        int n = s.size();
        for (int i = 1; i < n; i++) {
            while ((!result.empty()) && (s[i] < result.top()) && (k)) {
                result.pop();
                k--;
            }
            result.push(s[i]);
        }
        while (k--) result.pop();
        s = "";
        stack<char> temp;
        while (!result.empty())
            temp.push(result.top()), result.pop();
        while (!temp.top())
            temp.pop();
        while (!temp.empty())
            s.push_back(temp.top()), temp.pop();
        return s;
    }
};