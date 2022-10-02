// https://leetcode.com/problems/rotate-list

/*
~~~~~~~~~~~~~~~~~~~~~~~~~~~
--||author : codechaser||--
~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/
class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        if (k == 0)
        {
            return head;
        }

        int size = 1;
        ListNode *last = head;

        while (last->next != NULL)
        {
            last = last->next;
            size++;
        }

        k = size - (k % size);

        ListNode *curr = head;
        k--;
        while (curr && k--)
        {
            curr = curr->next;
        }

        last->next = head;

        head = curr->next;
        curr->next = NULL;

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