//https://leetcode.com/problems/maximum-sum-of-two-non-overlapping-subarrays/

class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int a, int b) {
           int n = nums.size();
    vector<int> pref(n + 1);
    pref[0] = nums[0];
    for (int i = 1; i < n; i++) {
        // calculating prefix sum
        pref[i] = pref[i - 1] + nums[i];
    }
    int ans = -1e9;
    // considering a always comes before b.

    // simply move the segment b and maximize segment a on the way
    int curr = pref[a - 1];
    for (int i = a; i < n; i++) {
        //considering second array to its right
        if (i + b <= n) {
            int second_sublist_pos = i + b - 1;
            int discarding_first_sublist_sum = i - 1;
            ans = max(ans, pref[second_sublist_pos] - pref[discarding_first_sublist_sum] + curr);
        }
        // updating curr if its smaller than its next sub array of length a 
        curr = max(curr, pref[i] - pref[i - a]);
    }
    // swap a and b
    swap(a, b);
    curr = pref[a - 1];
    for (int i = a; i < n; i++) {
        if (i + b <= n) {
            ans = max(ans, pref[i + b - 1] - pref[i - 1] + curr);
        }
        curr = max(curr, pref[i] - pref[i - a]);
    }
    return ans;
    }
};