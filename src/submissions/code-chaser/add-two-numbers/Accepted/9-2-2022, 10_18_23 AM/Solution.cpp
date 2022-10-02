// https://leetcode.com/problems/add-two-numbers

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum = 0;
        ListNode* resultHead = new ListNode((l1 -> val + l2 -> val) % 10);
        int carry = (l1 -> val + l2 -> val) / 10;
        ListNode* curr = resultHead;
        l1 = l1 -> next, l2 = l2 -> next;
        while ((l1 != nullptr) && (l2 != nullptr)) {
            curr -> next = new ListNode((l1 -> val + l2 -> val + carry) % 10);
            carry = (l1 -> val + l2 -> val + carry) / 10;
            l1 = l1 -> next, l2 = l2 -> next;
            curr = curr -> next;
        }
        while (l1 != nullptr) {
            curr -> next = new ListNode((l1 -> val + carry) % 10);
            carry = (l1 -> val + carry) / 10;
            l1 = l1 -> next;
            curr = curr -> next;
        }
        while (l2 != nullptr) {
            curr -> next = new ListNode((l2 -> val + carry) % 10);
            carry = (l2 -> val + carry) / 10;
            l2 = l2 -> next;
            curr = curr -> next;
        }
        if (carry > 0)
            curr -> next = new ListNode(carry % 10);
        return resultHead;
    }
};