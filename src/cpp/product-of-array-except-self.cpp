class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>prefix_pro(nums.size());
        prefix_pro[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            prefix_pro[i]=prefix_pro[i-1]*nums[i];
        }
        
        vector<int>sufix_pro(nums.size());
        sufix_pro[nums.size()-1]=nums[nums.size()-1];
        for(int i=nums.size()-2;i>=0;i--){
            sufix_pro[i]=sufix_pro[i+1]*nums[i];
        }
        vector<int>ans(nums.size());
        
        for(int i=0;i<nums.size();i++){
            if(i==0) ans[i]=sufix_pro[1];
            else if(i==nums.size()-1) ans[i]=prefix_pro[nums.size()-2];
            else ans[i]=prefix_pro[i-1]*sufix_pro[i+1];
        }
        return ans;   
    }
};
