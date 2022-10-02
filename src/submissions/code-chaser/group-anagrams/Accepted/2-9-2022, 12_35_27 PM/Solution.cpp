// https://leetcode.com/problems/group-anagrams

#include <bits/stdc++.h>
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>,vector<string>> rec;
        for(int i=0;i<strs.size();i++){
            vector<int> temp(26,0);
            for(int j=0;j<strs[i].size();j++)
                temp[strs[i][j]-'a']++;
            rec[temp].push_back(strs[i]);
        }
        vector<vector<string>> res;
        for(auto i:rec) res.push_back(i.second);
        return res;
    }
};