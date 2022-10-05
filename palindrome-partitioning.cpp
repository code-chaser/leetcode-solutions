//https://leetcode.com/problems/palindrome-partitioning/


class Solution {
public:
    vector<vector<string>> ans;
    bool ispal(string s){
        if(s.size() == 1)   return true;
        string temp = s;
        reverse(temp.begin(),temp.end());
        return temp.compare(s) == 0 ? true : false;
    }
    void func(string s,int i,int j, vector<string> &temp){
        if(j==s.size() && i==s.size()){
            ans.push_back(temp);
            return;
        }
        if(j==s.size()){
            return;
        }
        string sub = s.substr(i,j-i+1);
        if(ispal(sub)){
            temp.push_back(sub);
            func(s,j+1,j+1,temp);
            temp.pop_back();
            func(s,i,j+1,temp);
        }
        else{
            func(s,i,j+1,temp);
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> temp;
        ans.clear();
        func(s,0,0,temp);
        return ans;
    }
};
