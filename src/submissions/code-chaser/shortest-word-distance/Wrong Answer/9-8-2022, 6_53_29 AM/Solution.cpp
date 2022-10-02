// https://leetcode.com/problems/shortest-word-distance

class Solution {
public:
    int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
        int distance = 0;
        bool word1Found = 0, word2Found = 0;
        for (int i = 0; i < wordsDict.size(); i++) {
            if (word1Found || word2Found)
                distance++;
            if (wordsDict[i] == word1) {
                word1Found = 1;
                if (word2Found)
                    return distance;
            }
            else if (wordsDict[i] == word2) {
                word2Found = 1;
                if (word1Found)
                    return distance;
            }
        }
        return distance;
    }
};