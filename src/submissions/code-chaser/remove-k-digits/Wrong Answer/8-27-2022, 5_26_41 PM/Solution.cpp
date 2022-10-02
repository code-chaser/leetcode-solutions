// https://leetcode.com/problems/remove-k-digits

class Solution {
public:
    string removeKdigits(string s, int k){
	string result = "";
	int n = s.size();
	for (int i = 0; (i <= (n-2)) && (k!=0); i++) {
		if (s[i+1] < s[i]) {
			s[i] = '!';
			k-=1;
}
}
for (auto i:s) {
	if (i != '!')
		result.push_back(i);
}
        int ind=0;
while (result[ind]=='0') ind++;
return result;
}

};