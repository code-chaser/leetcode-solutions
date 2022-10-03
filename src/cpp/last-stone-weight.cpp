class Solution {
public:
    //using maxheap concept
    int lastStoneWeight(vector<int>& stones) {
        make_heap(stones.begin(), stones.end());
        
        while(stones.size()>1){
            pop_heap(stones.begin(), stones.end());
            int first = stones.back();
            stones.pop_back();
            
            pop_heap(stones.begin(), stones.end());
            int second = stones.back();
            stones.pop_back();
            
            int diff = abs(first-second);
            if(diff>0){
                stones.push_back(diff);
                push_heap(stones.begin(),stones.end());
            }
        }
        if(stones.size() == 1)
            return stones[0];
        else    return 0;
    }
};