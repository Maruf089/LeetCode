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
    public ListNode reverseBetween(ListNode head, int left, int right) {
        if (head == null || left == right) return head;

        // Create a dummy node to handle edge case where left = 1
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode leftPrev = dummy;

        // 1. Skip to the node right before the sub-list starts
        for(int i=0;i<left-1;i++){
	        leftPrev = leftPrev.next;
        }

        ListNode current = leftPrev.next; // left node , leftPrev = node before left
        ListNode leftNode = leftPrev.next;
        ListNode rightNode = null;

                for(int i=0;i<right-left+1;i++){
	        ListNode nextCurrent = current.next;
	        current.next = rightNode;
	        rightNode = current;
	        current = nextCurrent;
        }
        // now current is node after right node
        leftNode.next = current;
        leftPrev.next = rightNode;
        
        return dummy.next;
    }
}