// https://leetcode.com/problems/plus-one

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> res;
        int carry = 1;
        for (int i = digits.size(); (i > 0); i--)
            res.push_back((digits[i - 1] + carry) % 10), carry = ((digits[i - 1] + carry) / 10);
        if (carry)
            res.push_back(1);
        reverse(res.begin(), res.end());
        return res;
    }
};