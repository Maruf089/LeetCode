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
        if(head==null) return head;
        ListNode dummy = new ListNode(0,head);
        ListNode head_ptr = dummy , fast_ptr = head;
        for (int i = 0; i < n; i++) {
            fast_ptr = fast_ptr.next;
        }

        while(fast_ptr != null){
            fast_ptr = fast_ptr.next;
            head_ptr = head_ptr.next;
        }
        head_ptr.next = head_ptr.next.next;

        return dummy.next;
    }
}