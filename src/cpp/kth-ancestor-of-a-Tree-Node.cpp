class TreeAncestor {
public:
    vector<vector<int> >up;
    vector<int>height;
    
    TreeAncestor(int n, vector<int>& parent) {
        // int x=log2(n)+2;
        up=vector<vector<int> >(n,vector<int>(20+1,0));
        height=vector<int>(n,-1);
        up[0][0]=0;
        for(int i=1;i<n;i++)up[i][0]=parent[i];
        height[0]=0;
        for(int i=1;i<=20;i++){
            for(int j=0;j<n;j++){
                if(j!=0)height[j]=height[parent[j]]+1;
                up[j][i]=up[up[j][i-1]][i-1];
            }
        }
        
        
    }
    
    int getKthAncestor(int node, int k) {
        if(height[node]<k)return -1;
        while(true){
            int x=log2(k);
            node=up[node][x];
            k-=(1<<x);
            if(k==0)break;
        }
        return node;
        // return 0;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */
