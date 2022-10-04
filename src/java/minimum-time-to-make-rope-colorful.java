/*Question:-Alice has n balloons arranged on a rope. You are given a 0-indexed string colors where colors[i] is the color of the ith balloon.

Alice wants the rope to be colorful. She does not want two consecutive balloons to be of the same color, so she asks Bob for help. Bob can remove some balloons from the rope to make it colorful. You are given a 0-indexed integer array neededTime where neededTime[i] is the time (in seconds) that Bob needs to remove the ith balloon from the rope.

Return the minimum time Bob needs to make the rope colorful.*/

 
//Solution//




class Solution {
    public int minCost(String colors, int[] neededTime) {
        int cost=0;
        int pos=0;
        for(int i=1;i<colors.length();i++){
			//update pos based on the character's time
            if(colors.charAt(i)==colors.charAt(pos)){
                if(neededTime[i]<neededTime[pos]){
                    cost+=neededTime[i];
                }
                else{
                    cost+=neededTime[pos];
                    pos=i; 
                }
            }
            else{
                pos=i;
            }
        }
        return cost;
    }
}

//Submission link:-https://leetcode.com/submissions/detail/814202644/
