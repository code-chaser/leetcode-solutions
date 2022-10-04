class Solution {
public:
    int maxArea(vector<int>& h) {
        int start=0;
        int end=h.size()-1;
        int max_area=0;
        while(start<end){
            int mini=min(h[start],h[end]);
            int b=end-start;
            int curr_area=mini*b;
            max_area=max(curr_area,max_area);
            if(h[start]<=h[end]){
                start=start+1;
            }
            else if(h[start]>h[end]){
                end=end-1;
            }
        }
        return max_area;
    }
};
