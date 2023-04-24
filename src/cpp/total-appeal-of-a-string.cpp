// https://leetcode.com/problems/total-appeal-of-a-string/
class Solution {
public:
    typedef long long ll;
    long long appealSum(string s) {
        ll ans=0;
        ll n=s.size();
        for(char a='a';a<='z';a++){
          vector<int> idx;
            idx.push_back(-1);
            for(int i=0;i<n;i++){
                if(s[i]==a)idx.push_back(i);
            }
            idx.push_back(n);
            ll sans=n*(n+1)/2LL;      // all substrings of binary string
            if(idx.empty())continue;
            for(int i=1;i<idx.size();i++){
                ll x=idx[i-1]+1,y=idx[i]-1;
                ll z=y-x+1;                           // strings of format 1 "0000" 1 being subtracted
                sans-=z*(z+1)/2;
            }
            ans+=sans;
        }
        return ans;
    }
};
