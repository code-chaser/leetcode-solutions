// Question - https://leetcode.com/problems/remove-duplicates-from-sorted-list/

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
    public ListNode deleteDuplicates(ListNode head) {
        
        if (head==null || head.next==null) {
            return head;
        }
        
        ListNode temp1=head, temp2=head.next;
        
        while (temp2!=null) {
            
            if (temp1.val==temp2.val) {
                temp2=temp2.next;
                temp1.next=temp2;
            } else {
                temp1=temp1.next;
                temp2=temp2.next;
            }
        }
        
        return head;
    }

}

// Submission - https://leetcode.com/submissions/detail/426116279/