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
    public void reorderList(ListNode head) {
        if(head==null || head.next==null) 
            return;
        
        Deque<ListNode>order = new ArrayDeque<>();
        ListNode curr = head;
        while(curr != null){
            order.addLast(curr);
            curr = curr.next;
        }
        ListNode dummy = new ListNode(0);
        curr = dummy;
        boolean assignFront = false;
        while(order.size() > 0){
           if(assignFront){
            curr.next = order.pollLast();
           }
           else curr.next = order.pollFirst();
           curr = curr.next;
           assignFront = !assignFront;
        }
        curr.next = null;
    }
}