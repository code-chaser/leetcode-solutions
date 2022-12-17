class Solution {
public:
    bool isPalindrome(string s) {
        int n = size(s);
        
        if(n == 1) return true; // if string size 1 then simple return true if symbol is present no need worry about we don't need remove question ask return 
        //true or false
        
        string str = "";
        for(int i=0; i<n; i++) if(isalnum(s[i])) str +=s[i]; // only put number and char not any symbol
        
        // converting whole string into uppercase
        transform(str.begin(), str.end(), str.begin(), ::toupper);
        
        int i=0,j=size(str)-1;
        
        while(i<j) {
            if(str[i] != str[j]) return false; // checking where two char are not same then return false
            i++,j--;
        }
        return true;
    }
};