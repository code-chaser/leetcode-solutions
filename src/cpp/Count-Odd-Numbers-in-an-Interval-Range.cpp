/*
~~~~~~~~~~~~~~~~~~~~~~~~~~~
--||author : ksanjeev284||-- 
~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/

class Solution {
public:
    int countOdds(int low, int high) {
        int p=0;
        for(int i=low;i<=high;i++)
        {
            
            if(i%2 != 0)
            {
                
                p++;
            }
        }
        return p;
    }
};
