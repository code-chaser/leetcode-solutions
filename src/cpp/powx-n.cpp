class Solution {
public:
    double myPow(double x, int n) {
        double ans=1;
        int base=n;
        if (base==INT_MIN&&(x==1||x==-1))
            return 1;
        else if(base==INT_MIN)
            return 0;
        n=abs(n);
        if (x==1)
            return 1;
        while(n!=0)
        {
            if(n&1)
            {
                ans=ans*x;
            }
            x=x*x;
            n=n>>1;
        }
        if(base<0)
            return 1/ans;
        else 
            return ans;
    }
};