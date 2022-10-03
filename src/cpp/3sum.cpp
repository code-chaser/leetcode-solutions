class Solution 
{
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size()<=2) return {};
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        if(nums[nums.size()-1]<0) return {};
        for(int i=0;i<nums.size()-2;i++){
            if(nums[i]>0)break;
            if(i>0 && nums[i]==nums[i-1]) continue;
            int j=i+1,k=nums.size()-1;
            while(k>j){
                int s=nums[k]+nums[j];
                if(nums[i]+s==0){
                    ans.push_back({nums[i],nums[j],nums[k]});
                    while(j<k && nums[j]==nums[j+1] ) j++;
                    while(j<k && nums[k]==nums[k-1] ) k--;
                    j++;
                    k--;
                }
                else if(nums[i]+s>0) k--;
                else j++;
            }
        }
        return ans;
        
    }
};
