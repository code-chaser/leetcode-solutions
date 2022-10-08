//https://leetcode.com/problems/sqrtx/
class Solution {
public:
    int mySqrt(int x) {
        if(x <= 1)  return x;
        long long int a = 1;
        long long int b = x/2;
        long long int ans = 0;
        while(a <= b){
            long long int mid = a + (b-a)/2;
            if(mid*mid == x){
                return mid;
            }
            else if(mid*mid > x){
                b = mid-1;
            }
            else{
                ans = mid;
                a = mid+1;
            }
        }
        return ans;
    }
};