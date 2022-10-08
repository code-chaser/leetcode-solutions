class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        vector<int> count;      
        sort(arr.begin(),arr.end());     
        int n=arr.size();
        int c=0;        
        for(int i=0;i<n-1;i++)
        {   
            c++;
            while(arr[i]==arr[i+1])
            {   
                c++;
                i++;
                if(i==n-1){break;}
            }
            count.push_back(c);
            c=0;
        }
        if(arr[n-1]!=arr[n-2])
        {
            count.push_back(1);
        }
        cout<<endl;    
        sort(count.begin(),count.end());
        for(int i=0;i<count.size()-1;i++)
        {    
            if(count[i]==count[i+1])
            {
                return 0;
            }
        }
        return 1;
    }
};