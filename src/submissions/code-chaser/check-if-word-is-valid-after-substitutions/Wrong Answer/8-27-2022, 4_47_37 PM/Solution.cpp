// https://leetcode.com/problems/check-if-word-is-valid-after-substitutions

class Solution {
public:
    bool isValid(string s) {
        int cntOfA = 0, cntOfB = 0, cntOfC = 0;
        for (char i : s) {
            cntOfA += (i == 'a');
            cntOfB += (i == 'b');
            cntOfC += (i == 'c');
            if (i == 'b') {
                if ((cntOfB - 1) != cntOfC)
                    return false;
            }
            if (cntOfB > cntOfA) {
                return false;
            }
            if (cntOfC > cntOfB) {
                return false;
            }
        }
        if (cntOfA != cntOfB || cntOfB != cntOfC) {
            return false;
        }
        return true;
 }

};