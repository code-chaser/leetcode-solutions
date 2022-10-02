// https://leetcode.com/problems/reverse-nodes-in-k-group

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr = head;
        int size = 0;
        while (curr) {
            size++;
            curr = curr -> next;
        }
        curr = head;
        ListNode* resultHead = nullptr;
        ListNode* prev = new ListNode(-1, head);
        bool flag = true;
        int COUNT = 0;
        while (COUNT < (size/k)) {
            ListNode *spotPrev = curr, *spotCurr = curr -> next;
            int count = 1;
            while (count < k) {
                ListNode* temp = spotCurr -> next;
                spotCurr -> next = spotPrev;
                spotPrev = spotCurr;
                spotCurr = temp;
                count++;
            }
            if (!resultHead) {
                 resultHead = spotPrev;
            }
            prev->next = spotPrev;
            curr->next = spotCurr;
            prev = curr;
            curr = curr->next;
            COUNT++;
        }
        return resultHead;
    }
};