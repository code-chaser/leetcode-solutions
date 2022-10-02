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
        int carry = 0;
        ListNode* l0 = new ListNode(-1);
        ListNode* curr = l0;
        while (l1 && l2) {
            int prevCarry = carry;
            carry = (l1 -> val + l2 -> val + prevCarry) / 10;
            ListNode* newNode = new ListNode((l1 -> val + l2 -> val + prevCarry) % 10);
            curr -> next = newNode;
            curr = newNode;
            l1 = l1 -> next;
            l2 = l2 -> next;
        }
        while (l1) {
            int prevCarry = carry;
            carry = (l1 -> val + prevCarry) / 10;
            ListNode* newNode = new ListNode((l1 -> val + prevCarry) % 10);
            curr -> next = newNode;
            curr = newNode;
            l1 = l1 -> next;
        }
        while (l2) {
            int prevCarry = carry;
            carry = (l2 -> val + prevCarry) / 10;
            ListNode* newNode = new ListNode((l2 -> val + prevCarry) % 10);
            curr -> next = newNode;
            curr = newNode;
            l2 = l2 -> next;
        }
        if (carry) {
            ListNode* newNode = new ListNode(carry);
            curr -> next = newNode;
        }
        return l0 -> next;
    }
};