// https://leetcode.com/problems/partition-list

/*
~~~~~~~~~~~~~~~~~~~~~~~~~~~
--||author : codechaser||-- 
~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/
class Solution
{
public:
    ListNode *partition(ListNode *head, int x)
    {
        if (head != nullptr && head->next != nullptr)
        {
            ListNode *curr = head;
            ListNode *prev = nullptr;
            ListNode *flag = nullptr;
            ListNode *temp;
            while (curr != nullptr)
            {
                temp = curr->next;
                if (curr->val >= x)
                    prev = curr;
                else
                {
                    if (flag == prev)
                    {
                        flag = curr;
                        prev = curr;
                    }
                    else
                    {
                        prev->next = temp;
                        if (flag == nullptr)
                        {
                            curr->next = head;
                            head = curr;
                            flag = head;
                        }
                        else
                        {
                            curr->next = flag->next;
                            flag->next = curr;
                            flag = flag->next;
                        }
                    }
                }
                curr = temp;
            }
        }
        return head;
    }
};
/*
    |---------------------------------------------------|
    |||   https://codeforces.com/profile/codechaser   |||
    |||   https://www.codechef.com/users/codechaser   |||
    |||        https://github.com/code-chaser         |||
    |---------------------------------------------------|
*/