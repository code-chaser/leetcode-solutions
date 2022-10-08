class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int acount[26]={0};
        int bcount[26]={0};
        for(int i=0;i<ransomNote.length();i++){
            char ch = ransomNote[i];
            acount[ch-'a']++;
        }
        for(int i=0;i<magazine.length();i++){
            char ch = magazine[i];
            bcount[ch-'a']++;
        }
        for(int i = 0; i < 26;i++){
            if(acount[i]!=0){
                if(acount[i]>bcount[i]){
                    return false;
                }
            }
        }
        return true;
    }
};