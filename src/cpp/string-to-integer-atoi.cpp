class Solution 
{
public:
    int myAtoi(string s) {
        int i=0,n=s.size(),sign=1;
        while(s[i]==' ' && i<n) i++;
        if(i==n) return 0;
        if(s[i]=='-') sign=-1,i++;
        else if(s[i]=='+') sign=1,i++;
        long long t=0;
        for(i;i<n;i++){
            if(s[i]>='0' && s[i]<='9'){
                t=t*10+(s[i]-'0');
                if(sign==1 && t>INT_MAX) return INT_MAX;
                if(sign==-1 && -t<INT_MIN) return INT_MIN;
                // cout<<t<<endl;
            }
            else break;
        }
        return sign*t;
    }
};
