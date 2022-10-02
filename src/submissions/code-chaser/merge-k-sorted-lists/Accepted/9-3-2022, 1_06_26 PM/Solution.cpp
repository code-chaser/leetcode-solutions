// https://leetcode.com/problems/merge-k-sorted-lists

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> nodes;
        for (ListNode* i : lists) {
            ListNode* curr = i;
            while (curr) {
                nodes.push({curr -> val, curr});
                curr = curr -> next;
            }
        }
        if (nodes.empty())
            return nullptr;
        ListNode* resultHead = nodes.top().second;
        resultHead -> next = nullptr;
        ListNode* curr = resultHead;
        nodes.pop();
        while (!nodes.empty()) {
            pair<int, ListNode*> front = nodes.top();
            nodes.pop();
            curr -> next = front.second;
            curr = curr -> next;
        }
        curr -> next = nullptr;
        return resultHead;
    }
};