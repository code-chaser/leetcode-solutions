class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int>m;
        int n=nums.size()/3;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        vector<int>v;
        for(int i=0;i<nums.size();i++){
            if(m[nums[i]]>n){
                v.push_back(nums[i]);
            }
        }
        unordered_map<int,int>m2;
        vector<int>ans;
        for(int i=0;i<v.size();i++){
            m2[v[i]]++;
            if(m2[v[i]]==1){
                ans.push_back(v[i]);
            }
        }
        
        return ans;
        
    }
};
