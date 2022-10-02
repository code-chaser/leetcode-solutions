class Solution {
public:
    vector<int> digitcount(int n){
        vector<int>cnt(10);
        while(n){
            cnt[n%10]++;
            n/=10;
        }
        return cnt;
    }
    bool reorderedPowerOf2(int n) {
        if(!(n&(n-1))) return 1;
        vector<int>t=digitcount(n);
        for(int i=0;i<31;i++){
            vector<int>x=digitcount((1<<i));
            int fl=1;
            for(int j=0;j<10;j++){
                if(t[j]!=x[j]){
                    fl=0;
                    break;
                }
            }
            if(fl) return 1;
        }
        return 0;
    }
};
