// Question - https://leetcode.com/problems/reverse-nodes-in-k-group/

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
    public ListNode reverseKGroup(ListNode head, int k) {
        
        int size=size(head);
        int iter=size/k;
        
        int l,r;
        int i=0;
        
        while (i!=iter) {
            
            l=k*i;
            r=l+(k-1);
            
            while (l<r) {
                ListNode left=getAt(head,l);
                ListNode right=getAt(head,r);
                
                int temp=left.val;
                left.val=right.val;
                right.val=temp;
                
                l++;
                r--;
            }
            
            i++;
            
        }
        
        return head;
    }
    
    static ListNode getAt(ListNode head, int ind) {
        if (ind==0) {
            return head;
        } else if (ind==size(head)-1) {
            ListNode temp=head;
            while (temp.next!=null) {
                temp=temp.next;
            }
            return temp;
        } else {
            ListNode temp=head;
            int i=0;
            
            while (i<ind) {
                temp=temp.next;
                i++;
            }
            return temp;
        }
    }
    
    
    static int size(ListNode head) {
        ListNode temp=head;
        int cnt=0;
        
        while (temp!=null) {
            cnt++;
            temp=temp.next;
        }
        
        return cnt;
    }
}

// Submission - https://leetcode.com/submissions/detail/526062059/