// https://leetcode.com/problems/trapping-rain-water

/*
~~~~~~~~~~~~~~~~~~~~~~~~~~~
--||author : codechaser||-- 
~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/
class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> mx = height, collect(height.size(),0);
        for(int i = 1; i < height.size(); i++) mx[i] = max(mx[i-1],height[i]), collect[i] = mx[i] - height[i];
        vector<int> mxR = height, collectR(height.size(),0);
        for(int i = height.size()-2; i > -1; i--) mxR[i] = max(mxR[i+1],height[i]), collectR[i] = mxR[i] - height[i];
        int ans = 0;
        for(int i = 0; i < height.size(); i++) ans += min(collect[i],collectR[i]);
        return ans;
    }
};
/*
    |---------------------------------------------------|
    |||   https://codeforces.com/profile/codechaser   |||
    |||   https://www.codechef.com/users/codechaser   |||
    |||        https://github.com/code-chaser         |||
    |---------------------------------------------------|
*/