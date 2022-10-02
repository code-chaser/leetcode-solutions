// https://leetcode.com/problems/first-bad-version

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        if(isBadVersion(1)) return 1;
        int l = 1, r = n;
        while (l < (r - 1)){
            int mid = r - ((r - l) >> 1);
            if(isBadVersion(mid)) r = mid;
            else l = mid;
        }
        return r;
    }
};