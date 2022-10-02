class Solution {
public:
    int trailingZeroes(int N) {
        int ans=0;
        while(N>0){
            ans=ans+(N/5);
            N=N/5;
        }
        return ans;
    }
};
