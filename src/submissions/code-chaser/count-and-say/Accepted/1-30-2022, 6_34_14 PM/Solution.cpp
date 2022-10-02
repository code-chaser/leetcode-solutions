// https://leetcode.com/problems/count-and-say

/*
~~~~~~~~~~~~~~~~~~~~~~~~~~~
--||author : codechaser||-- 
~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/
#include <bits/stdc++.h>
class Solution {
public:
    string solve(string s){
        int ind = 1;
        string res = "";
        for(int i = 1; i < s.size(); i++){
            if(s[i] != s[i-1]) res.push_back(ind + '0'), res.push_back(s[i-1]), ind = 1;
            else ind++;
        }
        res.push_back(ind + '0'), res.push_back(s[s.size()-1]), ind = 1;
        return res;
    }
    string countAndSay(int n) {
        string res="1";
        for(int i = 0; i < n-1; i++) res=solve(res);
        return res;
    }
};
////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
    |---------------------------------------------------|
    |||   https://codeforces.com/profile/codechaser   |||
    |||   https://www.codechef.com/users/codechaser   |||
    |||        https://github.com/code-chaser         |||
    |---------------------------------------------------|
*/
////////////////////////////////////////////////////////////////////////////////////////////////////////////