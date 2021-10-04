/*
~~~~~~~~~~~~~~~~~~~~~~~~~~~
--||author : codechaser||-- 
~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/
class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        if (head == nullptr)
            return head;
        auto result = head;
        if (head->next != nullptr)
            result = head->next;
        while (head != nullptr && head->next != nullptr)
        {
            auto forward1 = head->next, forward2 = forward1->next;
            if (forward2 != nullptr)
            {
                if (forward2->next != nullptr)
                    head->next = forward2->next;
                else
                    head->next = forward2;
            }
            else
            {
                head->next = forward2;
            }
            forward1->next = head;
            head = forward2;
        }
        return result;
    }
};
/*
    |---------------------------------------------------|
    |||   https://codeforces.com/profile/codechaser   |||
    |||   https://www.codechef.com/users/codechaser   |||
    |||        https://github.com/code-chaser         |||
    |---------------------------------------------------|
*/