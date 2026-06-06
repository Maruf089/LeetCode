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
        if(head==null) return null;
        ListNode tail = head;
        for(int i=0; i<k;i++){
            if(tail==null) return head;
            tail = tail.next;
        }
        ListNode newHead = reverse(head,tail);
        head.next = reverseKGroup(tail,k);

        return newHead;
    }
    public ListNode reverse(ListNode curr, ListNode end){
        ListNode tmp = null;
        while(curr != end){
            ListNode nextNode = curr.next;
            curr.next = tmp;
            tmp = curr;
            curr = nextNode;
        }
        return tmp;
    }
}