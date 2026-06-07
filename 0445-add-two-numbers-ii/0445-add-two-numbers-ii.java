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
    public ListNode addTwoNumbersWithReverse(ListNode r1, ListNode r2) {
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

    // FoLlOw Up: Could you solve it without reversing the input list?
    // Solution : YeS , Using Stack ( without final reverse)

    public ListNode addTwoNumbers(ListNode r1, ListNode r2) {

        Stack<Integer>st1 = new Stack<>();
        Stack<Integer>st2 = new Stack<>();
        while(r1!=null){
            st1.add(r1.val);
            r1 = r1.next;
        }
        while(r2!=null){
            st2.add(r2.val);
            r2 = r2.next;
        }

        ListNode dummyHead = new ListNode(); 

        int carry = 0;
        while(st1.size()>0 || st2.size()>0){
            int digit1 = (st1.size() > 0) ? st1.pop() : 0; 
            int digit2 = (st2.size()>0) ? st2.pop() : 0; 
            
            int sum = digit1 + digit2 + carry; 
            int digit = sum % 10; 
            carry = sum / 10; 

            dummyHead.val = digit;
            
            ListNode newNode = new ListNode(carry); 
            newNode.next = dummyHead; 
            dummyHead = newNode;
        }

        return carry == 0 ? dummyHead.next : dummyHead;

    }

}