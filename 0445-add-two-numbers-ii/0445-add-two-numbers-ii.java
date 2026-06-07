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
    public ListNode addTwoNumbers(ListNode r1, ListNode r2) {
        ListNode l1 = reverseList(r1);
        ListNode l2 = reverseList(r2);

        ListNode dummyHead = new ListNode(0); 
        ListNode tail = dummyHead; 
        int carry = 0;

        while (l1 != null || l2 != null || carry != 0) 
        { 
            int digit1 = (l1 != null) ? l1.val : 0; 
            int digit2 = (l2 != null) ? l2.val : 0; 
            
            int sum = digit1 + digit2 + carry; 
            int digit = sum % 10; 
            carry = sum / 10; 
            
            ListNode newNode = new ListNode(digit); 
            tail.next = newNode; 
            tail = tail.next; 
            
            l1 = (l1 != null) ? l1.next : null; 
            l2 = (l2 != null) ? l2.next : null; 
        }

        return reverseList(dummyHead.next);
        
    }
    public ListNode reverseList(ListNode head) {
        ListNode prev = null, temp;
        while (head != null) {
            // Keep the next node
            temp = head.next;
            // Reverse the link
            head.next = prev;
            // Update the previous node and the current node.
            prev = head;
            head = temp;    
        }    
        return prev;
    }
}