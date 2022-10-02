// https://leetcode.com/problems/permutation-sequence

/*
~~~~~~~~~~~~~~~~~~~~~~~~~~~
--||author : codechaser||--
~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/
class Solution
{
public:
    string getPermutation(int n, int k)
    {
        vector<int> numbers;
        int fact = 1;
        for (int i = 1; i < n; i++)
        {
            fact = fact * i;
            numbers.push_back(i);
        }
        numbers.push_back(n);

        string res = "";
        k = k - 1;
        while (true)
        {
            res = res + to_string(numbers[k / fact]);
            numbers.erase(numbers.begin() + k / fact);
            if (numbers.size() == 0)
            {
                break;
            }
            k = k % fact;
            fact = fact / numbers.size();
        }
        return res;
    }
};
/*
    |---------------------------------------------------|
    |||   https://codeforces.com/profile/codechaser   |||
    |||   https://www.codechef.com/users/codechaser   |||
    |||        https://github.com/code-chaser         |||
    |---------------------------------------------------|
*/