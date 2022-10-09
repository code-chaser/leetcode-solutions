class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> temp(nums.size());
        
        for(int i=0;i<nums.size();i++){
            temp[(k+i)%nums.size()]=nums[i];
        }
        
        nums=temp;
        
        return;
    }
};