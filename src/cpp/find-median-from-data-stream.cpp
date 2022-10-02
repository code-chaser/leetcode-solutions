/*
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
--||author : Mitternachtsmond||-- 
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/
class MedianFinder 
{
public:
    MedianFinder() {
        
    }
    priority_queue<int>pq1; // max-heap
    priority_queue<int,vector<int>,greater<int>>pq2; // min-heap
    void addNum(int num) {
        if(pq1.empty()){
            pq1.push(num);
            return;
        }
        if(pq1.size()==pq2.size()){
            if(num>pq2.top()){
                pq1.push(pq2.top());
                pq2.pop();
                pq2.push(num);
            }
            else pq1.push(num);
        }
        else{
            if(num>pq1.top()) pq2.push(num);
            else{
                pq2.push(pq1.top());
                pq1.pop();
                pq1.push(num);
            }
        }
    }
    double findMedian() {
        if(pq1.size()==pq2.size()) return (pq1.top()+pq2.top())/2.0;
        else return pq1.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
