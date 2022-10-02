// https://leetcode.com/problems/swap-nodes-in-pairs

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
    ListNode* swapPairs(ListNode* head) {
        auto result = head->next;
        while(head != nullptr && head->next != nullptr) {
            auto forward1 = head->next, forward2 = forward1->next;
            if(forward2 != nullptr) {
                if(forward2->next != nullptr)
                    head->next = forward2->next;
                else
                    head->next = forward2;
            }
            else {
                head->next = forward2;
            }
            forward1->next = head;
            head = forward2;
        }
        return result;
    }
};