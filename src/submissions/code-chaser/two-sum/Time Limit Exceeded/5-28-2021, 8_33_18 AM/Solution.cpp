// https://leetcode.com/problems/two-sum

/*
~~~~~~~~~~~~~~~~~~~~~~~~~~~
--||author : codechaser||-- 
~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/
using namespace std;
#define rep0(i,k,n) for(llint i=k;i<n;i++)
#define rep1(i,k,n) for(llint i=k;i>n;i--)
#define rep2(i,k,n,a) for(llint i=k;(i<n)&&(a);i++)
#define br cout<<"\n";
#define print0(x) for(auto i:x) cout<<i<<" "; br;
#define print1(x) for(auto i:x) cout<<i.first<<" "<<i.second<<"\n"; br;
#define input0(x) for(auto &i:x) cin>>i;
#define input1(x) for(auto &i:x) cin>>i.first>>i.second;
#define pb push_back
#define mp make_pair
#define setbits(x) __builtin_popcountll(x)
#define tzerobits(x) __builtin_ctzll(x)
#define lzerobits(x) __builtin_clzll(x)
#define fileinput freopen("input.txt","r",stdin);
#define fileoutput freopen("output.txt","w",stdout);
#define timestarts tttt=clock();
#define timeends cout<<"\ntime taken: "<<(((double)clock())-tttt)/((double)CLOCKS_PER_SEC) <<"\n\n";
typedef int llint;
typedef unsigned long long ull;
typedef long double ld;
typedef unsigned int uint;
typedef vector<llint> vl;
typedef pair<llint,llint> pll;
typedef pair<llint,string> pls;
typedef map<llint,llint> mll;
uint uintMax=4294967295;         //+(1<<32) - 1
int intMax=2147483647;           //+(1<<31) - 1
int intMin=-2147483648;          //-(1<<31)
ull ullMax=18446744073709551615; //+(1<<64) - 1
llint Max=9223372036854775807;   //+(1<<63) - 1
llint Min=-9223372036854775808;  //-(1<<63)
////////////////////////////////////////////////////////////////////////////////////////////////////////////
llint power(llint n, llint exp){
    llint res=1;
    while(exp){
        if(exp&1) res*=n,exp--;
        else n*=n,exp>>=1;
    }
    return res;
}
void ts(vector<pll>& v,llint od){
    llint n=v.size(),max=abs(v[0].second);
    rep0(i,1,n) if(abs(v[i].second)>max) max=abs(v[i].second);
    llint k=log10(max)+1;
    rep0(i,0,ceil((double)k/od)){
        vector<vector<pll>> record(power(10,od));
        rep0(j,0,n) (record[(llint)abs((llint)((v[j].second)%((llint)power(10,od*(i+1))))/power(10,od*i))]).pb(v[j]);
        llint counter=0;
        rep0(j,0,power(10,od)) for(auto k:record[j]) v[counter]=k,counter++;
    }
    return;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        llint n=nums.size();
        vector<int> ans(2);
        vector<pll> v,negs,poss;
        rep0(i,0,n){
            if(nums[i]<0) negs.pb(mp(i,nums[i]));
            else poss.pb(mp(i,nums[i]));
        }
        if(poss.size()) ts(poss,3);
        if(negs.size()) ts(negs,3);
        rep1(i,((int)negs.size())-1,-1) v.pb(negs[i]);
        rep0(i,0,(int)poss.size()) v.pb(poss[i]);
        rep0(i,0,n){
            llint tg=target-v[i].second,l=i+1,r=n-1,m=l+((r-l)>>1);
            while(l!=r){
                if(v[m].second<tg) l=m+1,m=l+((r-l)>>1);
                else if(v[m].second==tg) l=r=m;
                else r=m-1,m=l+((r-l)>>1);
            }
            if(v[m].second==tg){
                ans[0]=v[i].first,ans[1]=v[m].first;
                break;
            }
        }
    return ans;
    }
};
////////////////////////////////////////////////////////////////////////////////////////////////////////////