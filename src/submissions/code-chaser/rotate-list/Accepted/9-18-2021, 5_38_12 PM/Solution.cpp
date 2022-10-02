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
            return head;
        ListNode *node1 = head;
        ListNode *node2 = NULL;
        int count = 1;
        while (node1->next != NULL)
        {
            node2 = node1;
            node1 = node1->next;
            count++;
        }
        k = (k >= count ? k % count : k);
        for (int i = 0; i < k; i++)
        {
            node1->next = head;
            head = node1;
            node2->next = NULL;
            while (node1->next != NULL)
            {
                node2 = node1;
                node1 = node1->next;
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