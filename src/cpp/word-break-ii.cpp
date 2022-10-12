// Method 1
// (Deciding break or not break for each element.)

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

// Method 2
// (Can be improved to check presence by storing in unordered_set like Method 1 instead of iterating each time.)

bool isPresent(vector<string>& dictionary, string find) {
    for (int i = 0; i < dictionary.size(); i++) {
        if (dictionary[i] == find)return true;
    }
    return false;
}
void recur(vector<string>& ans, string& temp, vector<string>& dictionary, string& s, int index) {
    if (index == s.size()) {
        ans.push_back(temp.substr(0, temp.size() - 1));
        return;
    }
    for (int i = index; i < s.size(); i++) {
        if (isPresent(dictionary, s.substr(index, i - index + 1))) {
            string tempcopy = temp;
            tempcopy += s.substr(index, i - index + 1);
            tempcopy += " ";
            recur(ans, tempcopy, dictionary, s, i + 1);
        }
    }
}
vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    vector<string> ans;
    string temp = "";
    recur(ans, temp, dictionary, s, 0);

    return ans;
}
