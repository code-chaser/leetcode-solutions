class Solution {
public:
    int maxProduct(vector<int>& nums) {
        long long ans = -1e15;
        for(auto i : nums)ans=max(ans,(long long)i);
        
        vector<long long>dp;
        long long cur = 1;
        vector<int>neg;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                if(dp.size()==0)continue;
                ans=max(ans,cur);
                if(cur>0){
                    dp.clear();
                    cur=1;
                    neg.clear();
                    continue;
                }
                if(dp.size()==1){
                    dp.clear();
                    cur=1;
                    neg.clear();
                    continue;
                }
                int idx = neg.back();
                idx--;
                if(idx>=0)ans=max(ans,dp[idx]);
                
                idx = neg[0];
                long long X = dp.back()/dp[idx];
                ans=max(ans,X);
                dp.clear();
                cur=1;
                neg.clear();
                
            }else{
                cur*=nums[i];
                dp.push_back(cur);
                if(nums[i]<0){
                    neg.push_back((int)dp.size()-1);
                }
            }
        }
        
        if(dp.size()){
                ans=max(ans,cur);
                if(cur>0){
                    dp.clear();
                    cur=1;
                    neg.clear();
                
                }
                else if(dp.size()==1){
                    dp.clear();
                    cur=1;
                    neg.clear();
                   
                }
                else{
                    int idx = neg.back();
                idx--;
                if(idx>=0)ans=max(ans,dp[idx]);
                
                idx = neg[0];
                long long X = dp.back()/dp[idx];
                ans=max(ans,X);
                dp.clear();
                cur=1;
                neg.clear();
                }
        }
        return ans;
        
    }
};
