// https://leetcode.com/problems/count-vowels-permutation

static vector<vector<int>> relation={{1},{0,2},{0,1,3,4},{2,4},{0}};
class Solution {
public:
    int MOD=1e9+7;
    vector<vector<int>> memo;
    int dp(int n,int v)
    {
        if(n==1)
            return 1;
        if(memo[n][v]!=-1)
            return memo[n][v];
        memo[n][v]=0;
        for(int &i:relation[v])
            memo[n][v]+=dp(n-1,i),memo[n][v]%=MOD;
        return memo[n][v];
    }
    int countVowelPermutation(int n) 
    {
        int result=0;
        memo.resize(n+1,vector<int>(5,-1));
        for(int i=0;i<5;i++)
            result+=dp(n,i),result%=MOD;
        return result;
    }
};