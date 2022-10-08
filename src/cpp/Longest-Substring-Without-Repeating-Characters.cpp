class Solution
{
    public:
        int lengthOfLongestSubstring(string s)
        {
            unordered_map<char, int> m;
            int i = 0;
            int j = 0;
            int ans = 0;
            while (j < s.size())
            {
                m[s[j]]++;
                if (j - i + 1 == m.size())
                {
                    ans = max(ans, j - i + 1);
                }
                else
                {
                    while (m.size() < j - i + 1)
                    {
                        m[s[i]]--;
                        if (m[s[i]] == 0)
                        {
                            m.erase(s[i]);
                        }
                        i++;
                    }
                    ans = max(ans, j - i + 1);
                }
                j++;
            }
            return ans;
        }
};
