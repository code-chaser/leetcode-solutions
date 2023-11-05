// https://leetcode.com/problems/candy/

/*
The input is interpreted as consisting of "hills" and "valleys" . All valleys will greedily have 1 candy and the no of 
candies will gradually increase by 1 for each level we move up from this valley . A valley will contribute to the answer 
of both hills to its left as well as to it's right , so traversing the input twice once in forward direction and one in 
reverse and then taking the maximum of the 2 contributions will give us the answer.
*/

class Solution {
public:
    int candy(vector<int>& ratings) {
     int n=ratings.size();
     int pre[n],suf[n];
      pre[0]=1;
      for(int i=1;i<n;i++){
          if(ratings[i]>ratings[i-1])pre[i]=pre[i-1]+1;     // we climb 1 level on the hill to the right
          else pre[i]=1;
      }
       suf[n-1]=1;
        for(int i=n-2;i>-1;i--){
            if(ratings[i]>ratings[i+1])suf[i]=suf[i+1]+1;    // we climb 1 level on the hill to the left
            else suf[i]=1;
        }
        int ans=0;
        for(int i=0;i<n;i++)ans+=max(suf[i],pre[i]);
        return ans;
    }
};
