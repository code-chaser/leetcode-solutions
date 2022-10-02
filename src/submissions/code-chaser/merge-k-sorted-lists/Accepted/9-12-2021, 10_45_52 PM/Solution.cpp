// https://leetcode.com/problems/merge-k-sorted-lists

/*
~~~~~~~~~~~~~~~~~~~~~~~~~~~
--||author : codechaser||-- 
~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/
class Solution
{
    ListNode *merge(vector<ListNode *> &lists, int left, int right)
    {
        if (left == right)
            return lists[left];
        int k = right - left + 1;
        ListNode *p1 = NULL, *p2 = NULL, *head = NULL, *p;
        p1 = merge(lists, left, left + k / 2 - 1);
        p2 = merge(lists, (left + k / 2), right);
        if (!p1 && !p2)
            return head;
        else if (!p1)
            return p2;
        else if (!p2)
            return p1;

        if (!p2 || (p2 && p1->val < p2->val))
        {
            head = p1;
            p1 = p1->next;
        }
        else
        {
            head = p2;
            p2 = p2->next;
        }
        p = head;
        while (p1 or p2)
        {
            if (!p1)
            {
                p->next = p2;
                p2 = p2->next;
                p = p->next;
            }
            else if (!p2)
            {
                p->next = p1;
                p1 = p1->next;
                p = p->next;
            }
            else if (p1->val < p2->val)
            {
                p->next = p1;
                p1 = p1->next;
                p = p->next;
            }
            else
            {
                p->next = p2;
                p2 = p2->next;
                p = p->next;
            }
        }
        return head;
    }

public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        int k = lists.size();
        if (k == 0)
            return NULL;
        if (k == 1)
            return lists[0];
        ListNode *head = NULL, *p1 = NULL, *p2 = NULL, *p;
        p1 = merge(lists, 0, k / 2);
        if ((k / 2) + 1 <= k - 1)
        {
            p2 = merge(lists, (k / 2) + 1, k - 1);
        }
        if (!p1 && !p2)
            return head;
        else if (!p1)
            return p2;
        else if (!p2)
            return p1;
        if (!p2 || (p2 && p1->val < p2->val))
        {
            head = p1;
            p1 = p1->next;
        }
        else
        {
            head = p2;
            p2 = p2->next;
        }
        p = head;
        while (p1 or p2)
        {
            if (!p1)
            {
                p->next = p2;
                p2 = p2->next;
                p = p->next;
            }
            else if (!p2)
            {
                p->next = p1;
                p1 = p1->next;
                p = p->next;
            }
            else if (p1->val < p2->val)
            {
                p->next = p1;
                p1 = p1->next;
                p = p->next;
            }
            else
            {
                p->next = p2;
                p2 = p2->next;
                p = p->next;
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