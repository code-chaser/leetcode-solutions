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
        if (k == 1)
            return head;
        ListNode* curr = head;
        int n = 0;
        while (curr) {
            n += 1;
            curr = curr -> next;
        }
        curr = head;
        ListNode* prev = head = new ListNode(-1, curr);
        int count = 0;
        while (count < floor(n / k)) {
            ListNode* spotCurr = curr -> next;
            ListNode* spotPrev = prev -> next;
            int spotCount = 1;
            while (spotCount < k) {
                ListNode* next = spotCurr -> next;
                spotCurr -> next = spotPrev;
                spotPrev = spotCurr;
                spotCurr = next;
                spotCount += 1;
            }
            prev -> next = spotPrev;
            curr -> next = spotCurr;
            prev = curr;
            curr = spotCurr;
            count += 1;
        }
        return head -> next;
    }
};