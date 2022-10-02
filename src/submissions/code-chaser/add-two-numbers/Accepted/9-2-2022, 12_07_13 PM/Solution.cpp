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
        if (!(l1 && l2))
            return l1 ? l1 : l2;
        ListNode* resultHead = l1;
        ListNode* curr = nullptr;
        while (l1 && l2) {
            curr = l1;
            int tempCarry = carry;
            carry = (l1 -> val + l2 -> val + tempCarry) / 10;
            curr -> val = (l1 -> val + l2 -> val + tempCarry) % 10;
            l1 = l1 -> next;
            l2 = l2 -> next;
        }
        if (l1) {
            curr -> next = l1;
            while (l1) {
                curr = l1;
                int tempCarry = carry;
                carry = (l1 -> val + tempCarry) / 10;
                curr -> val = (l1 -> val + tempCarry) % 10;
                l1 = l1 -> next;
            }
        }
        else {
            curr -> next = l2;
            while (l2) {
                curr = l2;
                int tempCarry = carry;
                carry = (l2 -> val + tempCarry) / 10;
                curr -> val = (l2 -> val + tempCarry) % 10;
                l2 = l2 -> next;
            }
        }
        if (carry) {
            curr -> next = new ListNode(carry);
        }
        return resultHead;
    }
};