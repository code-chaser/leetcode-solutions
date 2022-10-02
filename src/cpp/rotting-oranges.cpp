class Solution {
public:
    int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
    int orangesRotting(vector<vector<int>>&arr) {
        int m=arr.size();
        int n=arr[0].size();
        int time=0;
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(arr[i][j]==2){
                    q.push({i,j});
                    arr[i][j]=-1;
                }
            }         
        }
        while(q.size()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                pair<int,int>curr=q.front();
                q.pop();
                for(int j=0;j<4;j++){
                    int r=curr.first+dir[j][0];
                    int c=curr.second+dir[j][1];
                    if(r<0||c<0||r>m-1||c>n-1||arr[r][c]!=1)
                        continue;
                    q.push({r,c});
                    arr[r][c]=-1;
                }
            }
            time++;
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(arr[i][j]==1)
                    return -1;
            }
        }
        return time!=0? time-1:time;;
    }
};
