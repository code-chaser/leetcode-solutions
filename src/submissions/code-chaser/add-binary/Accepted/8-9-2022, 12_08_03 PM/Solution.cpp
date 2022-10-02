// https://leetcode.com/problems/add-binary

class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        bool carry = 0;
        for (int i = 0; i < min(a.size(), b.size()); i++) {
            switch (a[a.size() - 1 - i] + b[b.size() - 1 - i] - '0' + carry) {
                case '0':
                    res.push_back('0');
                    break;
                case '1':
                    res.push_back('1');
                    carry = 0;
                    break;
                case '2':
                    res.push_back('0');
                    carry = 1;
                    break;
                case '3':
                    res.push_back('1');
                    break;
            }
        }
        string l,r;
        switch (a.size() < b.size()) {
            case 0:
                l = b, r = a;
                break;
            case 1:
                l = a, r = b;
                break;
        }
        for (int i = r.size() - l.size() - 1; i >= 0; i--) {
            switch (r[i] + carry) {
                case '0':
                    res.push_back('0');
                    break;
                case '1':
                    res.push_back('1');
                    carry = 0;
                    break;
                case '2':
                    res.push_back('0');
                    break;
            }
        }
        if (carry)
            res.push_back('1');
        reverse(res.begin(), res.end());
        return res;
    }
};