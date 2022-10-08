/*
1338. Reduce Array Size to The Half
You are given an integer array arr. You can choose a set of integers and remove all the occurrences of these integers in the array.
Return the minimum size of the set so that at least half of the integers of the array are removed.

Example:
Input: arr = [3,3,3,3,5,5,5,2,2,7]
Output: 2
Explanation: Choosing {3,7} will make the new array [5,5,5,2,2] which has size 5 (i.e equal to half of the size of the old array).
Possible sets of size 2 are {3,5},{3,2},{5,2}.
Choosing set {2,7} is not possible as it will make the new array [3,3,3,3,5,5,5] which has a size greater than half of the size of the old array.

Example2:
Input: arr = [7,7,7,7,7,7]
Output: 1
Explanation: The only possible set you can choose is {7}. This will make the new array empty.

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int> map;
        int n=arr.size();
        for(int i=0;i<arr.size();i++){
            map[arr[i]]++;
        }
        vector<int> frequency;
        for(auto it:map){
            frequency.push_back(it.second);
        }
        sort(frequency.begin(),frequency.end());
        int ans=0;
        int check=n/2;
        for(int l=frequency.size()-1;l>=0;l--){
            if(n-frequency[l]<=check){
                ans++;
                break;
            }else{
                n-=frequency[l];
                ans++;
            }
        }
        return ans;
    }
};