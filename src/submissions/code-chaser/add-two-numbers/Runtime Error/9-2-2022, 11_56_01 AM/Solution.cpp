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
        ListNode* prev = nullptr;
        ListNode* curr = l1;
        while (l1 || l2 || carry) {
            int tempCarry = carry;
            if (l1 && l2) {
                carry = (l1 -> val + l2 -> val + carry) / 10;
                curr ->  val = (l1 -> val + l2 -> val + tempCarry) % 10;
                l1 = l1 -> next;
                l2 = l2 -> next;
                curr = curr -> next;
            }
            else if (l1) {
                carry = (l1 -> val + carry) / 10;
                curr -> val = (l1 -> val + tempCarry) % 10;
                prev = l1;
                l1 = l1 -> next;
                curr = curr -> next;
            }
            else if (l2) {
                carry = (l2 -> val + carry) / 10;
                curr -> val = (l2 -> val + tempCarry) % 10;
                if (!(prev -> next)) prev -> next = l2;
                prev = l2;
                l2 = l2 -> next;
                curr = curr -> next;
            }
            else if (carry) {
                prev -> next = new ListNode(carry);
                carry = 0;
            }
        }
        return resultHead;
    }
};