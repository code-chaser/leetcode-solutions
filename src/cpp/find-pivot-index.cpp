class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        
        int sum=0;
        
        for(int i=0;i<nums.size();i++){
            
            sum+=nums[i];
            
        }
        
        int presum=0;
        
        for(int i=0;i<nums.size();i++){
            
            if(presum==sum-presum-nums[i]){
                
                return i;
                
            }else{
                
                presum+=nums[i];
                
            }
        }
        
        return -1;
    }
};