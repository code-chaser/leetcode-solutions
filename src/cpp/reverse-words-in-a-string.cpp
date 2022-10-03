class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        int i=0;
        vector<string>temp;
        string t="";
        for(int i=0;i<n;i++){
            if(s[i]!=' ') t.push_back(s[i]);
            else{
                if(t!="") temp.push_back(t);
                t="";
            }
        }
        if(t!="") temp.push_back(t);
        string ans="";
        for(int i=temp.size()-1;i>=0;i--){
            ans=ans+temp[i]+' ';
        }
        ans.pop_back();
        return ans;
    }
};
