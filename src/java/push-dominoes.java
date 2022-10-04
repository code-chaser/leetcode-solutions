/*Question:-There are n dominoes in a line, and we place each domino vertically upright. In the beginning, we simultaneously push some of the dominoes either to the left or to the right.

After each second, each domino that is falling to the left pushes the adjacent domino on the left. Similarly, the dominoes falling to the right push their adjacent dominoes standing on the right.

When a vertical domino has dominoes falling on it from both sides, it stays still due to the balance of the forces.

For the purposes of this question, we will consider that a falling domino expends no additional force to a falling or already fallen domino.

You are given a string dominoes representing the initial state where:

dominoes[i] = 'L', if the ith domino has been pushed to the left,
dominoes[i] = 'R', if the ith domino has been pushed to the right, and
dominoes[i] = '.', if the ith domino has not been pushed.
Return a string representing the final state.*/

class Solution {
    public String pushDominoes(String dominoes) {
        
        StringBuilder sb = new StringBuilder(dominoes);
        
        int n = sb.length();
        
        
        //mark true for all the unpushed block, after pushing a bloch in right direction
        char prev = '.';
        boolean[] forward = new boolean[n];
        for(int i = 0; i < n; i++){
            char c = dominoes.charAt(i);
            if(c == '.'){
                if(prev == 'R') forward[i] = true; 
            }else{
                prev = c;
            }
        }
        
        //mark true for all the unpushed block, after pushing a block in left direction
        prev = '.';
        boolean[] backward  = new boolean[n];
        for(int i = n - 1; i >= 0; i--){
            char c = dominoes.charAt(i);
            if(c == '.'){
                if(prev == 'L') backward[i] = true; 
            }else{
                prev = c;
            }
        }
        
        int i = 0;
        while(i < n){
            if(backward[i] && !forward[i]){
                //fall block as there is force in left direction
                sb.setCharAt(i++, 'L');
                
            }else if(!backward[i] && forward[i]){
                //fall block as there is force in right direction
                sb.setCharAt(i++, 'R');
                
            }else if(backward[i] && forward[i]){
                //fall block as there is force in both  direction
                int j = (i + 1);
                while(j < n && backward[j] && forward[j]){
                    j++;
                }
                pushDominoesInBetween(sb, i, j - 1);
                i = j;
            }else{
                i++;
            }
            
        }
        
        return sb.toString();
    }
    
    
    private void pushDominoesInBetween(StringBuilder sb, int l, int r){
        while(l < r){
            sb.setCharAt(l++, 'R');
            sb.setCharAt(r--, 'L');
        }
        
    }
}

//submission link:-https://leetcode.com/submissions/detail/809846444/
