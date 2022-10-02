// https://leetcode.com/problems/copy-list-with-random-pointer

/*
~~~~~~~~~~~~~~~~~~~~~~~~~~~
--||author : codechaser||-- 
~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/
class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        Node *front = head;
        for (Node *i = head; i != NULL;)
        {
            front = i->next;
            Node *copy = new Node(i->val);
            i->next = copy;
            copy->next = front;
            i = front;
        }
        for (Node *i = head; i != NULL;)
        {
            if (i->random != NULL)
            {
                i->next->random = i->random->next;
            }
            i = i->next->next;
        }
        Node *pseudo = new Node(0);
        Node *copy = pseudo;
        for (Node *i = head; i != NULL;)
        {
            front = i->next->next;
            copy->next = i->next;
            i->next = front;
            copy = copy->next;
            i = front;
        }
        return pseudo->next;
    }
};
/*
    |---------------------------------------------------|
    |||   https://codeforces.com/profile/codechaser   |||
    |||   https://www.codechef.com/users/codechaser   |||
    |||        https://github.com/code-chaser         |||
    |---------------------------------------------------|
*/