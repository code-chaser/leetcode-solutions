// https://leetcode.com/problems/remove-k-digits

#include <bits/stdc++.h>
class Solution {
public:
    string removeKdigits(string num, int k) {
        int n=num.size(), lastInd=0, kcopy=k;
        string result;
        multimap<char,int> m;
        for(int i=0; i<k; i++)
            m.insert(make_pair(num[i],i));
        for(int i=0; (k > 0) && ((kcopy+i) < num.size()); i++){
            multimap<char,int> newm;
            for(auto j:m)
                if(j.second>=lastInd)
                    newm.insert(j);
            newm.insert(make_pair(num[kcopy+i],kcopy+i));
            m=newm;
            result.push_back(m.begin()->first);
            k -= ((m.begin()->second)-lastInd);
            lastInd = m.begin()->second+1;
        }
        result += num.substr(lastInd, num.size()-lastInd);
        num="",k=0;
        for(int i=0; i<result.size(); i++) if((result[i]-'0')||k) num.push_back(result[i]),k=1;
        return num;
    }
};