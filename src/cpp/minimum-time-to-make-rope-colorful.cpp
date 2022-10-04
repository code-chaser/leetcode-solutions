class Solution 
{
public:
    int minCost(string colors, vector<int>& nt) {
        int n=colors.size();
        if(n==1) return 0;
        int ans=0,csum=nt[0],cmax=nt[0];
        char prev=colors[0];
        for(int i=1;i<n;i++){
            if(prev==colors[i]){
                csum+=nt[i];
                cmax=max(cmax,nt[i]);
            }
            else{
                ans=ans+(csum-cmax);
                prev=colors[i];
                csum=cmax=nt[i];
            }
        }
        ans=ans+(csum-cmax);
        return ans;
    }
};
