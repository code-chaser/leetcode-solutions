/*
~~~~~~~~~~~~~~~~~~~~~~~~~~~
--||author : codechaser||-- 
~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/
class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *prev = NULL;
        ListNode *curr = head;
        ListNode *next;
        int count = 0;
        ListNode *temp = head;
        int c = 0;
        while (c < k && temp != NULL)
        {
            temp = temp->next;
            c++;
        }
        if (c < k)
            return curr;
        while (curr != NULL && count < k)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }
        if (next != NULL)
            head->next = reverseKGroup(next, k);
        return prev;
    }
};
/*
    |---------------------------------------------------|
    |||   https://codeforces.com/profile/codechaser   |||
    |||   https://www.codechef.com/users/codechaser   |||
    |||        https://github.com/code-chaser         |||
    |---------------------------------------------------|
*/