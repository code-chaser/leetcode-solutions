class Solution {
    public boolean isPalindrome(int x) {
        String first = Integer.toString(x);
        String second = "";

        for (int i = first.length()-1; i >= 0; i--) {
            second = second + first.charAt(i);
        }
        if (first.equals(second)){
            return true;
        } else {return false;}
    }
}