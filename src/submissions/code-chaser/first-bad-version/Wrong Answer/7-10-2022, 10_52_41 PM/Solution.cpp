// https://leetcode.com/problems/first-bad-version

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        if(n == 1) return n;
        int l = 1, r = n + 1;
        while (l < (r - 1)){
            int mid = r - ((r + 1 - l) >> 1);
            if(isBadVersion(mid)) r = mid;
            else l = mid;
        }
        return r;
    }
};