class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        if(nums.size()<=1) return 0;
        
        unordered_map<int, int> mp;
        mp[0] = -1;
        
        int cnt = (nums[0] == 1 ? 1 : -1);
        mp[cnt] = 0;
        
        int maxi = 0;
        
        for(int i = 1; i<nums.size(); i++){
            cnt = (nums[i] == 1)? cnt+1 : cnt-1;
            
            if(mp.find(cnt) != mp.end())
                maxi = max(maxi, i-mp[cnt]);
            else
                mp[cnt] = i;
        }
        
        return maxi;
    }
};