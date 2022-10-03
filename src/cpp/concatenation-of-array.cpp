
// Author - Shadowpii

class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        
        for(int i=0;i<2*n;i++){
            int x;
            x = nums[i%n];
            ans.push_back(x);
        }
        
        return ans;
    }
};