class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>>stk;
        for(int i=0;i<s.size();i++){
            if(stk.size()==0) stk.push({s[i],1});
            else if(stk.top().first==s[i]){
               int x= stk.top().second+1;
                if(x==k){
                    for(int i=k-1;i>=1;i--){
                         stk.pop();
                    }
                }
                else{
                    stk.push({s[i],x});
                }
            } 
            else{
                stk.push({s[i],1});
            }
        }
        string ans="";
        while(stk.empty()==false){
            ans.push_back(stk.top().first);
            stk.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
