// Question - https://leetcode.com/problems/remove-nth-node-from-end-of-list/

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        
        int size=size(head);
        
        if (size==n) {
            return head.next;
        }
        
        int i=0;
        ListNode temp=head;
        
        while (i<size-n-1) {
            temp=temp.next;
            i++;
        }
        
        temp.next=temp.next.next;
        
        return head;
    }
    
    int size (ListNode head) {
        
        int count=0;
        
        while (head!=null) {
            count++;
            head=head.next;
        }
        
        return count;
    }
}

// Submission - https://leetcode.com/submissions/detail/810498154/