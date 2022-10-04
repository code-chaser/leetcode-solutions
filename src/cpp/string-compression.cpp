class Solution {
public:
    void put(vector<char>& s, int count){
        string c=to_string(count);
        for(int i=0;i<c.length();i++){
            s.push_back(c[i]);
        }
    }
    int compress(vector<char>& chars) {
        int count=1;
        vector<char> s;
        s.push_back(chars[0]);
        for(int i=1;i<chars.size();i++){
            if(chars[i]==chars[i-1]){
                count++;
            }
            else{
                if(count>1){
                    put(s,count);
                }
                s.push_back(chars[i]);
                count=1;
            }
        }
        if(count>1)
            put(s,count);
        chars=s;
        return chars.size();
    }
};