class Solution 
{
public:
    typedef long long ll;
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if(nums.size()<=3) return {};
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>>ans;
        for(int i=0;i<n-3;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            for(int j=i+1;j<n-2;j++){
                if(j>1 && nums[j]==nums[j-1] && i!=j-1) continue;
                int k=j+1,l=n-1;
                ll sum=nums[i]+nums[j];
                while(l>k){
                    if(nums[k]+nums[l]+sum==target){
                        cout<<i<<" "<<j<<" "<<k<<" "<<l<<endl;
                        ans.push_back({nums[i],nums[j],nums[k],nums[l]});
                        while(l>k && nums[l]==nums[l-1]) l--;
                        while(l>k && nums[k]==nums[k+1]) k++;
                        l--,k++;
                    }
                    else if(nums[l]+nums[k]+sum>target) l--;
                    else k++;
                }
                
            }
        }
        return ans;
    }
};
