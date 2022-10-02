// https://leetcode.com/problems/swap-nodes-in-pairs

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

        if (head == NULL)
            return NULL;

        if (head && head->next == NULL)
            return head;

        ListNode *curr = head->next;
        ListNode *pre = head;
        ListNode *last = NULL;

        head = head->next;

        while (curr)
        {

            if (last)
                last->next = curr;

            pre->next = curr->next;
            curr->next = pre;

            last = pre;
            pre = pre->next;

            if (pre)
                curr = pre->next;
            else
                break;
        }

        return head;
    }
};
////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
    |---------------------------------------------------|
    |||   https://codeforces.com/profile/codechaser   |||
    |||   https://www.codechef.com/users/codechaser   |||
    |||        https://github.com/code-chaser         |||
    |---------------------------------------------------|
*/
////////////////////////////////////////////////////////////////////////////////////////////////////////////