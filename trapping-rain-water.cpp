class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        if(n==0){
            return 0;
        }
        int*left_max=new int[n];
        int*right_max=new int[n];
        int x=height[0];
        for(int i=0;i<n;i++){
            x=max(x, height[i]);
            left_max[i]=x;
        }
        x=height[n-1];
        for(int i=n-1;i>=0;i--){
            x=max(x, height[i]);
            right_max[i]=x;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans=ans+min(left_max[i], right_max[i])-height[i];
        }
        return ans;
    }
};
