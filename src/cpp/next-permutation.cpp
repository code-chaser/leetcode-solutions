class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size()==0 || nums.size()==1)
            return;
        int i,j,f=1;
        for(i=nums.size()-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                f=0;
                break;
            }
        }
        if(f)
            reverse(nums.begin(),nums.end());
        else
        {
            for(j=nums.size()-1;j>i;j--){
                if(nums[j]>nums[i])
                    break;
            }
            swap(nums[i],nums[j]);
            reverse(nums.begin()+i+1,nums.end());
        }
    }
    
};
