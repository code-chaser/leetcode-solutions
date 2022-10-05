class Solution 
{
public:
    string intToRoman(int num) {
        // string t=to_string(num);
        string ans="";
        if(num/1000){
            int d=num/1000;
            for(int i=1;i<=d;i++) ans.push_back('M');
            num%=1000;    
        }
        if(num/100){
            int d=num/100;
            if(d==5) ans.push_back('D');
            else if(d==4) ans=ans+"CD";
            else if(d==9) ans=ans+"CM";
            else if(d<=3) for(int i=1;i<=d;i++) ans.push_back('C');
            else{
                ans.push_back('D');
                for(int i=1;i<=(d-5);i++) ans.push_back('C');
            }
            num%=100;
        }
        if(num/10){
            int d=num/10;
            if(d==5) ans.push_back('L');
            else if(d==4) ans=ans+"XL";
            else if(d==9) ans=ans+"XC";
            else if(d<=3) for(int i=1;i<=d;i++) ans.push_back('X');
            else{
                ans.push_back('L');
                for(int i=1;i<=(d-5);i++) ans.push_back('X');
            }
            num%=10;
        }
        if(num){
            int d=num;
            if(d==5) ans.push_back('V');
            else if(d==4) ans=ans+"IV";
            else if(d==9) ans=ans+"IX";
            else if(d<=3) for(int i=1;i<=d;i++) ans.push_back('I');
            else{
                ans.push_back('V');
                for(int i=1;i<=(d-5);i++) ans.push_back('I');
            }
        }
        return ans;
    }
};
