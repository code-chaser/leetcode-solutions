// https://leetcode.com/problems/copy-list-with-random-pointer

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* curr = head;
        while (curr) {
            Node* newNode = new Node(curr -> val);
            newNode -> next = curr -> next;
            curr -> next = newNode;
            curr = newNode -> next;
        }
        
        curr = head;
        while (curr) {
            curr -> next -> random = (curr -> random) ? curr -> random -> next : nullptr;
            curr = curr -> next -> next;
        }
        
        Node* resultHead = head -> next;
        curr = head;
        while (curr) {
            Node* temp = curr -> next;
            curr -> next = temp ? (temp -> next) : nullptr;
            curr = temp;
        }
        
        return resultHead;
    }
};