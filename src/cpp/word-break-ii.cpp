class Solution {
public:
    void recur(string& s, unordered_set<string>& wordSet, int ind, int startInd, vector<string>& res, string& temp) {
        if (ind == s.size() - 1) {
            if (wordSet.find(s.substr(startInd, ind - startInd + 1)) != wordSet.end()) {
                string tempcopy = temp;
                tempcopy += s.substr(startInd, ind - startInd + 1);
                res.push_back(tempcopy);
            }
            return;
        }

        if (wordSet.find(s.substr(startInd, ind - startInd + 1)) != wordSet.end()) {
            string tempcopy = temp;
            tempcopy += s.substr(startInd, ind - startInd + 1) + " ";
            recur(s, wordSet, ind + 1, ind + 1, res, tempcopy);
        }
        recur(s, wordSet, ind + 1, startInd, res, temp);
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set <string> wordSet;
        for (int i = 0; i < wordDict.size(); i++) {
            wordSet.insert(wordDict[i]);
        }
        vector<string> res;
        string temp = "";
        recur(s, wordSet, 0, 0, res, temp);
        return res;
    }
};
