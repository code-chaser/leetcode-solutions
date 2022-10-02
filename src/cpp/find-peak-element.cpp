class Solution {
public:
    int findPeakElement(vector<int>& arr) {
    int n=arr.size();
    if(n==1) return 0;
    int start=0,end=n-1;
    int mid;

    while(end>=start){

        mid=(start+end)/2;

        if(mid == 0){
            if(arr[mid] >= arr[mid+1]) break;
            else start=mid+1;
        }

        else if(mid == n-1){
            if(arr[mid] >= arr[mid-1]) break; 
            else end=mid-1;
        }
        else if((arr[mid] >= arr[mid-1]) && (arr[mid] >=arr[mid+1])) break;
        else if(arr[mid] < arr[mid-1]) end=mid-1;
        else start=mid+1;
    }
    return mid;
    }
};
