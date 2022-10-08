class Solution {
public:
    int strStr(string haystack, string needle) {
        // KMP algorithm
        int x=needle.size();
        needle.push_back('*');
        int n=needle.size();
        int lps[n];
        lps[0]=0;
        for(int i=1;i<n;i++){
            int j=lps[i-1];
            while(j>0 && needle[i]!=needle[j]) j=lps[j-1];
            if(needle[i]==needle[j]) j++;
            lps[i]=j;
        }
        int cval=0;
        for(int i=0;i<haystack.size();i++){
            int j=cval;
            while(j>0 && needle[j]!=haystack[i]) j=lps[j-1];
            if(needle[j]==haystack[i]) j++;
            cval=j;
            if(cval==n-1) return i-x+1;
        }
        return -1;
    }
};
