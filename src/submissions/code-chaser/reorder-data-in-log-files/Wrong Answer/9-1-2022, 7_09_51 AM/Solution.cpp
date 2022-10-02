// https://leetcode.com/problems/reorder-data-in-log-files

class Solution {
private:
    static bool cmp(string a, string b) {
        bool aType = 0, bType = 0; // 0:letter, 1:digit;
        
        int ind = 0;
        while (a[ind++] != ' ');
        if (a[ind] >= '0' && a[ind] <= '9')
            aType = 1;
        string aContents = a.substr(ind, a.size() - ind);
        
        ind = 0;
        while (b[ind++] != ' ');
        if (b[ind] >= '0' && b[ind] <= '9')
            bType = 1;
        string bContents = b.substr(ind, b.size() - ind);
        
        if (aType && bType)
            return false;
        if (aType && (!bType))
            return false;
        if ((!aType) && bType)
            return true;
        if (aContents == bContents)
            return a < b;
        return aContents < bContents;
    }
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> sorted = logs;
        sort(sorted.begin(), sorted.end(), cmp);
        return sorted;
    }
};