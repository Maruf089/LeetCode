/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode detectCycleWithSet(ListNode head) {
        Set<ListNode> seen = new HashSet<>();
        while(head != null){
            if(seen.contains(head)) return head;
            seen.add(head);
            head = head.next;
        }
        return null;
        
    }

    public ListNode detectCycle(ListNode head) {
        ListNode slow = head , fast = head;
        while(fast!=null && fast.next!=null){
            slow = slow.next;
            fast = fast.next.next;
            if(slow==fast) break;
        }
        if(fast==null || fast.next==null) return null;

        fast = head;
        while(fast!=slow){
           fast = fast.next;
           slow = slow.next;
        }

        return fast;
        
    }
}