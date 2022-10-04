class Solution 
{
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int>ans(m+n);
        int a1,a2;
        a1=a2=0;
        while(a1!=m&& a2!=n){
            if(nums1[a1]<nums2[a2]){ ans[a1+a2]=nums1[a1];a1++;}
            else{ ans[a1+a2]=nums2[a2];a2++;}
        }
        // for(int i=0;i<a1+a2-1;i++) cout<<ans[i]<<" ";
        while(a1!=m){
            ans[a1+a2]=nums1[a1];
            a1++;
        }
        while(a2!=n){
            ans[a1+a2]=nums2[a2];
            a2++;
        }
        for(int i=0;i<m+n;i++) nums1[i]=ans[i];
        
    }
};
