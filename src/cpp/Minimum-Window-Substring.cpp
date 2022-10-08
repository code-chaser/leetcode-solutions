class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> m;
        int i = 0;
        int j = 0;
        int ans = INT_MAX;
        int index = 0;
        for (auto i : t)
        {
            m[i]++;
        }
        int count = m.size();
        while (j < s.size())
        {
            if (m.find(s[j]) != m.end())
            {
                m[s[j]]--;
                if (m[s[j]] == 0)
                    count--;
            }
            if (count == 0)
            {
                while (count == 0)
                {
                    if (m.find(s[i]) != m.end())
                    {
                        m[s[i]]++;
                        
                        if (m[s[i]] == 1)
                        {
                          count++;
                            if (ans > j - i + 1){
                                index = i;
                                ans = j - i + 1;
                            }

                        }
                    }
                    i++;
                }
            }
            j++;
        }
        if (ans == INT_MAX)
            return "";
        return s.substr(index,ans);
    }
};
