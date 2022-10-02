// https://leetcode.com/problems/two-sum

bool cmp(pair<int, int> a, pair<int, int> b) {
        return (a.first) < (b.first);
}
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        vector<pair<int, int>> v;
        for (int i = 0; i < nums.size(); i++)
            v[i].first = nums[i], v[i].second = i;
        sort(v.begin(), v.end());
        for (auto i = v.begin(); i != v.end(); i++) {
            auto j = lower_bound(i + 1, v.end(), make_pair(target - (i->first), 0), cmp);
            if ((j->first) == (target - (i->first))) {
                ans.push_back(v[i - v.begin()].second);
                ans.push_back(v[j - v.begin()].second);
                break;
            }
        }
        return ans;
    }
};