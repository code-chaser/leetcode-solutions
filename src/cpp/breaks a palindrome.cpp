class Solution {
public:
    string breakPalindrome(string palindrome) {
        // EITHER A OR B
        int n = palindrome.length();
        if(n == 1)return "";
        int cnt = 1,pos = n - 1;
        char c = palindrome[n/2];
        for(int i = 0; i < n; i++){
            if(palindrome[i] != 'a'){
                cnt--;
                palindrome[i] = 'a';
                pos = i;
                break;
            }
        }
        if((n&1) and pos == n/2){
            palindrome[pos] = c;
            palindrome[n - 1] = 'b';
        }
        if(cnt){
            palindrome[n - 1] = 'b';
        }
        return palindrome;
    }
};

you can check the solution on https://leetcode.com/problems/break-a-palindrome/submissions/