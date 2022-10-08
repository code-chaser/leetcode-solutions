//https://leetcode.com/problems/jump-game-ii/

class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() == 1)    return 0;
        int maxReach = nums[0], currReach = nums[0];
        int count = 1;
        if(maxReach >= nums.size()-1)   return count;
        
        for(int i=0; i<=maxReach; i++){
            maxReach = max(maxReach,nums[i]+i);
            
            if(maxReach >= nums.size()-1)   return count+1;
            if(i == currReach){
                currReach = maxReach;
                count++;
            }
        }
        return -1;
    }
};