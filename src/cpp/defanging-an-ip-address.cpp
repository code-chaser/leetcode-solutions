class Solution {
public:
    string defangIPaddr(string address) {
        string ans="";
        for(int i=0;i<address.length();i++){
            if(address[i]=='.'){
                ans+="[.]";
            }
            else{
                ans+=address[i];
            }
        }
        return ans;
    }
};
//https://leetcode.com/submissions/detail/791753767/