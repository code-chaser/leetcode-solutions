class Solution {
    public String reverseWords(String s) {
        String[] temp=s.trim().split(" ");
        String ans="";
        for(int i=temp.length-1;i>0;i--){
            if(temp[i]!="") ans=ans+temp[i]+" ";
        }
        ans=ans+temp[0];
        return ans;
    }
}
