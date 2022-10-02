/* The isBadVersion API is defined in the parent class VersionControl.
boolean isBadVersion(int version); */

public class Solution extends VersionControl {
    public int firstBadVersion(int n) {
        int i = 1;
        int j = n;
        
        int ans = j;
        while (i <= j) {
            int m = i + (j-i)/2;
            if (isBadVersion(m)) {
                ans = m;
                j=m-1;
            }
            else {
                i=m+1;
            }
        }
        return ans;
    }
}
// Submission Link: https://leetcode.com/problems/first-bad-version/submissions/634890233/