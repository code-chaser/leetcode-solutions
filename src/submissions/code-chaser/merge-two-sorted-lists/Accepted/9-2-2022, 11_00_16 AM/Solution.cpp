// https://leetcode.com/problems/merge-two-sorted-lists

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!(list1 && list2))
            return list1 ? list1 : list2;
        ListNode* resultHead = nullptr;
        ListNode* last = nullptr;
        while (list1 && list2) {
            if ((list1 -> val) < (list2 -> val)) {
                if (resultHead) last = last -> next = list1;
                else resultHead = last = list1;
                list1 = list1 -> next;
            }
            else {
                if (resultHead) last = last -> next = list2;
                else resultHead = last = list2;
                list2 = list2 -> next;
            }
        }
        if (list1) {
            last = last -> next = list1;
        }
        if (list2) {
            last = last -> next = list2;
        }
        return resultHead;
    }
};