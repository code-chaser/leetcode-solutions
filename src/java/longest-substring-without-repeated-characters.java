class Solution {
    public int lengthOfLongestSubstring(String s) {
        if (s.length() == 0) return 0;
        int curStartingIdx = 0;
        ArrayList<Character> substring = new ArrayList<Character>();
        int maxValue = 0;
        for (int i = 0; i < s.length(); i++) {
            if (!substring.contains(s.charAt(i))){
                substring.add(s.charAt(i));
                if (maxValue < substring.size()) {
                    maxValue = substring.size();
                }
            } else {
                substring.clear();
                curStartingIdx++;
                i = curStartingIdx-1;
            }
        }

        return maxValue;
    }
}