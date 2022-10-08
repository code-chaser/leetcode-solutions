class Solution {
public:
    bool validSubStr(unordered_map<string,int> cnt, string str, int size){
        for(int i=0;i<str.size();i+=size){
            string currStr = str.substr(i,size);
            if(cnt.find(currStr) != cnt.end()){
                if(--cnt[currStr] == -1) return false;
            }else{
                return false;
            }
        }
        return true;
    }
    
    vector<int> findSubstring(string s, vector<string>& word) {
        unordered_map<string,int> cnt;
        for(int i=0;i<word.size();i++){
            cnt[word[i]]++;
        }
        
        int wordLen = word[0].size();
        int windowSize = word.size()*wordLen;
        
        int i = 0;
        vector<int> ans;
        
        while(i+windowSize <= s.size()){
            if(validSubStr(cnt,s.substr(i,windowSize),wordLen)){
                ans.push_back(i);
            }
            i++;
        }
        return ans;
    }
};
