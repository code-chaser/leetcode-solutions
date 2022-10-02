// https://leetcode.com/problems/sort-list

/*
~~~~~~~~~~~~~~~~~~~~~~~~~~~
--||author : codechaser||-- 
~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/
class Solution
{
public:
    void mergesorting(ListNode **head)
    {
        ListNode *curr = *head;
        ListNode *first;
        ListNode *second;
        if (!curr || !curr->next)
            return;
        findmid(curr, &first, &second);
        mergesorting(&first);
        mergesorting(&second);
        *head = mergeboth(first, second);
    }
    ListNode *sortList(ListNode *head)
    {
        mergesorting(&head);
        return head;
    }
    ListNode *mergeboth(ListNode *first, ListNode *second)
    {
        ListNode *answer = NULL;
        if (!first)
            return second;
        if (!second)
            return first;
        if (first->val <= second->val)
        {
            answer = first;
            answer->next = mergeboth(first->next, second);
        }
        else
        {
            answer = second;
            answer->next = mergeboth(first, second->next);
        }
        return answer;
    }
    void findmid(ListNode *curr, ListNode **first, ListNode **second)
    {
        ListNode *fast = curr->next;
        ListNode *slow = curr;
        while (!fast)
        {
            fast = fast->next;
            if (!fast)
            {
                fast = fast->next;
                slow = slow->next;
            }
        }
        *first = curr;
        *second = slow->next;
        slow->next = NULL;
    }
};
/*
    |---------------------------------------------------|
    |||   https://codeforces.com/profile/codechaser   |||
    |||   https://www.codechef.com/users/codechaser   |||
    |||        https://github.com/code-chaser         |||
    |---------------------------------------------------|
*/