//https://leetcode.com/problems/single-threaded-cpu/

class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> opq;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        int n = tasks.size();
        if(n == 0)  return {};
        vector<int> ans;
        for(int k=0;k<n;k++){
            opq.push({tasks[k][0],tasks[k][1],k});
        }
        long long int t = int(opq.top()[0]);
        while(!opq.empty()){
            while(!opq.empty() && t >= opq.top()[0]){
                pq.push({opq.top()[1],opq.top()[2]});
                opq.pop();
            }
            if(!pq.empty()){
                auto tp = pq.top();
                pq.pop();
                t += tp.first;
                ans.push_back(tp.second);
            }
            else{
                t = int(opq.top()[0]);
            }
        }
        while(!pq.empty()){
            auto tp = pq.top();
            pq.pop();
            t += tp.first;
            ans.push_back(tp.second);
        } 
        return ans;
    }
};