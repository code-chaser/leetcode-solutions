class Solution {
public:
    bool isequal(int a[26],int b[26]){
        for(int i=0;i<26;i++){
            if(a[i]!=b[i])
                return 0;
        }
        return 1;
    }
    bool checkInclusion(string s1, string s2) {
        int count1[26]={0};
        for(int i=0;i<s1.size();i++){
            count1[s1[i]-'a']++;
        }
        int count2[26]={0};
        int windowsize=s1.size();
        int i=0;
        for(i=0;i<windowsize && i<s2.length();i++){
            count2[s2[i]-'a']++;
        }
        if(isequal(count1,count2)){
                return 1;
        }
        for(;i<s2.length();i++){
            count2[s2[i]-'a']++;
            count2[s2[i-windowsize]-'a']--;
            if(isequal(count1,count2)){
                return 1;
            }
        }
        return 0;
    }
};