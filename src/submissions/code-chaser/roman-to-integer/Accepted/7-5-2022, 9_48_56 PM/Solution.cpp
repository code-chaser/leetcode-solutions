// https://leetcode.com/problems/roman-to-integer

class Solution {
public:
    map<int, int> val = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
    int romanToInt(string s) {
        int curr = val[s[s.size()-1]];
        for(int i = s.size()-2; i >= 0; i--) {
            if (val[s[i]] < val[s[i+1]]) curr -= val[s[i]];
            else curr += val[s[i]];
        }
        return curr;
    }
};