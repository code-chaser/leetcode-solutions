/*
~~~~~~~~~~~~~~~~~~~~~~~~~~~
--||author : codechaser||-- 
~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *last = head, *lastToLast = NULL, *temp;
        while (last != NULL)
        {
            temp = last->next;
            last->next = lastToLast;
            lastToLast = last;
            last = temp;
        }
        return lastToLast;
    }
};
/*
    |---------------------------------------------------|
    |||   https://codeforces.com/profile/codechaser   |||
    |||   https://www.codechef.com/users/codechaser   |||
    |||        https://github.com/code-chaser         |||
    |---------------------------------------------------|
*/