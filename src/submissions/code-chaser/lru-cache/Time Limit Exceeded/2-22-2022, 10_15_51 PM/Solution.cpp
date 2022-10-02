// https://leetcode.com/problems/lru-cache

class LRUCache {
private:
    map<int,int> cache, status, pointr;
    int k=INT_MIN;
    stack<int> LRUstack;
    int capacity;
public:
    LRUCache(int capacity) {
        this->capacity=capacity;
    }
    
    int get(int key) {
        if(cache.find(key)!=cache.end()){
            pointr.erase(status[key]);
            status[key]=k;
            pointr[k]=key;
            k++;
            return cache[key];
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(!capacity) return;
        if(cache.find(key)!=cache.end()){
            pointr.erase(status[key]);
            cache[key] = value;
            status[key] = k;
            pointr[k] = key;
            k++;
        }
        else if(cache.size()<capacity){
            cache[key] = value;
            status[key]=k;
            pointr[k]=key;
            k++;
        }
        else{
            for(auto i : pointr){
                status.erase(i.second);
                cache.erase(i.second);
                pointr.erase(i.first);
                break;
            }
            cache[key] = value;
            status[key]=k;
            pointr[k]=key;
            k++;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */