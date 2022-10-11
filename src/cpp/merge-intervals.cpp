class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) { //brute force
        int n = intervals.size();
        if(n == 1) return intervals;
        vector<vector<int>> ans;
        
        sort(intervals.begin() , intervals.end());
        
        vector<int> curr = intervals[0];
        for(int i=1 ; i<n ; i++){
            if(curr[1] >= intervals[i][0]) curr[1] = max(curr[1] , intervals[i][1]);
            else{
                ans.push_back(curr);
                curr = intervals[i];
            }
        }
        ans.push_back(curr);
        return ans;
    }
};