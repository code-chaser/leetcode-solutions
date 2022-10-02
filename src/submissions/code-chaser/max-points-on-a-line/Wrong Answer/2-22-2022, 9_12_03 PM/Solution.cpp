// https://leetcode.com/problems/max-points-on-a-line

#include<bits/stdc++.h>
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size(), ans = 1;
        for(int i = 0; i < n; i++){
            int infinity = 0;
            map<int, int> cnt;
            for(int j = i+1; j < n; j++){
                int dx = points[i][0] - points[j][0];
                int dy = points[i][1] - points[j][1];
                if(!dx) infinity++, ans = max(ans, infinity+1);
                else{
                    int g = __gcd(dx, dy);
                    dx /= g, dy /= g;
                    cnt[dx*dy]++;
                    ans = max(ans, cnt[dx*dy]+1);
                }
            }
        }
        return ans;
    }
};