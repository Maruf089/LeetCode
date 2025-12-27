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
    public ListNode rotateRight(ListNode head, int k) {
        if(head==null) return head;
        int len = 0;
        ListNode curr = head;
        while(curr!=null){
            len++;
            curr = curr.next;
        }
        int position = k % len;
        if(len==1 || position==0) return head;

        curr = head;
        int needToStop = len - position - 1;
        while(curr!=null && needToStop > 0){
            needToStop--;
            curr = curr.next;
        }

        ListNode nextNode = curr.next;
        ListNode dummy = curr.next;
        curr.next = null;

        while(nextNode.next != null){
            nextNode = nextNode.next;
        }
        nextNode.next = head;

        return dummy;   
    }
}