// https://leetcode.com/problems/remove-duplicates-from-sorted-list

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        vector<bool> present(201, 0);
        present[head -> val + 100] = 1;
        ListNode *prev = head, *curr = head -> next;
        while(curr != nullptr) {
            if(present[curr -> val + 100])
                curr = prev -> next = curr -> next;
            else
                prev = curr, curr = curr -> next;
        }
        return head;
    }
};