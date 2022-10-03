/*
	Author: Hasan Enes Şimşek
	Link: https://leetcode.com/submissions/detail/683979053/
*/

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int prev = arr[arr.size()-1];
        for(int i = arr.size()-2; i >= 0; i--)
        {
            if(arr[i+1] > prev)
            {
                prev = arr[i];
                arr[i] = arr[i+1];    
            }
            else
            {
                int temp = prev;
                prev = arr[i];
                arr[i] = temp;
            }
            
        }
        arr[arr.size()-1] = -1;
        return arr;
    }
};