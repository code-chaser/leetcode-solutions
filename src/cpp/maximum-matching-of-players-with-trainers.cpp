//https://leetcode.com/contest/biweekly-contest-87/problems/maximum-matching-of-players-with-trainers/

class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& p, vector<int>& t) {
        sort(p.begin(),p.end());
        int ans = 0;
        multiset<int> s;
        for(auto x: t){
           s.insert(x);
        }
        for(auto x: p){
            auto it = s.lower_bound(x);
            if(it == s.end())   break;
            ans++;
            s.erase(it);
        }
        return ans;
    }
};