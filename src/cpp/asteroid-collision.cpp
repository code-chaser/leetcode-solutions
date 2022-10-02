class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        stack<int>s;
        vector<int>v;
        s.push(a[0]);
        
        for(int i=1;i<a.size();i++){
            if(a[i]>0) s.push(a[i]);
            else{
                int f=0;
                while(s.empty()==false && s.top()>0 ){
                   if(s.top()==abs(a[i])){
                       s.pop();
                       f=1;
                       break;
                   }
                else if(s.top()<abs(a[i])){
                    s.pop();
                    
                }
               else{
                   f=1;
                   break;
               }    
            }
            if(f==0) s.push(a[i]);
           
        }
    }
         while(s.empty()==false){
            v.push_back(s.top());
             s.pop();
        }
        reverse(v.begin(),v.end());
        return v;
    }
};
