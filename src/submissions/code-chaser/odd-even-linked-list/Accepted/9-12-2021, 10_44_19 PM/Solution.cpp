// https://leetcode.com/problems/odd-even-linked-list

/*
~~~~~~~~~~~~~~~~~~~~~~~~~~~
--||author : codechaser||-- 
~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/
class Solution
{
public:
    ListNode *oddEvenList(ListNode *head)
    {
        if (head == NULL)
            return head;
        ListNode *odd = head;
        ListNode *curr = head->next;
        while (curr && curr->next)
        {
            ListNode *even = odd->next;
            odd->next = curr->next;
            odd = odd->next;
            curr->next = odd->next;
            odd->next = even;
            curr = curr->next;
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