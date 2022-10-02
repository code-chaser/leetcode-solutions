// https://leetcode.com/problems/pascals-triangle

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        vector<int> row = {1};
        res.push_back(row);
        if (numRows == 1) {
            return res;
        }
        row.push_back(1);
        res.push_back(row);
        if (numRows == 2) {
            return res;
        }
        numRows -= 2;
        while (numRows--) {
            vector<int> nextRow = {1};
            for (int i = 0; i < row.size() - 1; i++) {
                nextRow.push_back(row[i] + row[i + 1]);
            }
            nextRow.push_back(1);
            row = nextRow;
            res.push_back(row);
        }
        return res;
    }
};