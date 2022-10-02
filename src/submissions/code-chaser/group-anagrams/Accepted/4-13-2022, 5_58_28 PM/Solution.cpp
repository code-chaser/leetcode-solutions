// https://leetcode.com/problems/group-anagrams

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n=strs.size();
        vector<vector<string>> res;
        map<vector<int>,vector<string>> m;
        for(int i=0;i<n;i++){
            vector<int> v(128,0);
            for(auto j:strs[i]) v[j]++;
            m[v].push_back(strs[i]);
        }
        for(auto i:m) res.push_back(i.second);
        return res;
    }
};