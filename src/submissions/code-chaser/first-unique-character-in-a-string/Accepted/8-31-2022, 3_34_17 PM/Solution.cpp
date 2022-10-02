// https://leetcode.com/problems/first-unique-character-in-a-string

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> freqMap;
        for (char i : s)
            freqMap[i]++;
        for (int i = 0; i < s.size(); i++)
            if (freqMap[s[i]] == 1)
                return i;
        return -1;
    }
};