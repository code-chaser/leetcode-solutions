class Solution {
public:
    int dp[15][32768];
    bool canMake(string &s,unordered_map<char,int> &m)
    {
        unordered_map<char,int> n=m;
        for(auto i: s)
        {
            if(n[i]<=0)
                return false;
            n[i]--;
        }
        return true;
    }
    int find(string &s,unordered_map<char,int> &m,vector<int>&score)
    {
        int ans=0;
        for(int i=0;i<s.length();i++)
        {
            m[s[i]]--;
            ans+=score[s[i]-'a'];
        }
        return ans;
    }
    void undochange(string &s,unordered_map<char,int> &m)
    {
        for(int i=0;i<s.length();i++)
        {
            m[s[i]]++;
            
        }
    }
    int sol(vector<string>& words, unordered_map<char,int> &m, vector<int>& score,int curr,int mask)
    {
        if(curr>=words.size())
        {
            return 0;
        }
        if(dp[curr][mask]!=-1)
            return dp[curr][mask];
        
        int ans=0;
        for(int i=curr;i<words.size();i++)
        {
            if(canMake(words[i],m))
            {
                int s=find(words[i],m,score);
                int op1=s+sol(words,m,score,i+1,(1<<i)|mask);
                ans=max(ans,op1);
                undochange(words[i],m);
            }
            
        }
        return dp[curr][mask]=  ans;
        
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) 
    {
        memset(dp,-1,sizeof(dp));
        unordered_map<char,int> m;
        for(int i=0;i<letters.size();i++)
        {
            m[letters[i]]++;
        }
        return sol(words,m,score,0,0);
        
        
    }
};
