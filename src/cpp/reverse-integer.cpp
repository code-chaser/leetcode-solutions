class Solution 
{
public:
    int reverse(int x) {
        if(x==0) return 0;
        int sign=1,e=-1;
        if(x==INT_MIN) return 0;
        if(x<0) sign=-1,x=-x;
        int temp=x;
        int num=0;
        while(temp!=0){
            int z=temp%10;
            if((num) > INT_MAX/10) return 0;
           
            num*=10;
            num=(num+z);temp/=10;
        }
        // if(num==INT_MAX && sign==-1) return 0;
        return num*sign;
        
    }
};
