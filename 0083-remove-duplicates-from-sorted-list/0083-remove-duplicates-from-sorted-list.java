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
        ListNode dummy = new ListNode();
        ListNode curr = dummy;
        while(head != null){
            curr.next = head;
            while(head.next != null && head.val==head.next.val){
                    head.next = head.next.next;
            }
            head = head.next;
            curr = curr.next;
        }
        return dummy.next;
        
    }
}