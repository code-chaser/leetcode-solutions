class Solution {
int getTranslateNum(char s) {
    switch(s) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0;
    }
    return 0;
}
public:
    int romanToInt(string s) {
        if(s.empty()) return 0;
        int returnValue = 0;
        for(unsigned int i=0; i<s.size()-1; i++) {
            if(getTranslateNum(s[i]) < getTranslateNum(s[i+1])) {
                returnValue -= getTranslateNum(s[i]);
            } else {
                returnValue += getTranslateNum(s[i]);
            }
        }
        returnValue += getTranslateNum(s[s.size()-1]);
        return returnValue;
    }
};

// https://leetcode.com/submissions/detail/814767425/
