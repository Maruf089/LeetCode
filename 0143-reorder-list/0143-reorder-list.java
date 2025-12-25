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
    public void reorderListWithDeque(ListNode head) {
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

    public void reorderListWithStack(ListNode head) {
        if(head==null || head.next==null) 
            return;

        ListNode slow = head , fast = head;

        // find middle, slow will be at middle
        while(fast!=null && fast.next!=null){
            slow = slow.next;
            fast = fast.next.next;
        }

        // 2) Push second half into stack
        Stack<ListNode> st = new Stack<>();
        ListNode curr = slow.next;
        while (curr != null) {
            st.push(curr);
            curr = curr.next;
        }

        // 3) Cut first half to prevent cycles
        slow.next = null;

        // 4) Merge: first half + popped nodes
        curr = head;
        while (!st.isEmpty()) {
            ListNode back = st.pop();
            if (curr == null) break;

            ListNode nextFront = curr.next;

            curr.next = back;
            back.next = nextFront;
            curr = nextFront;
        }
    }

    public void reorderList(ListNode head) {
        if(head==null || head.next==null) 
            return;

        ListNode slow = head , fast = head;

        // find middle, slow will be at middle
        while(fast!=null && fast.next!=null){
            slow = slow.next;
            fast = fast.next.next;
        }

        // 2) reverse 2nd half
        ListNode curr = slow.next , secondHalf = null , tmp = null;
        while (curr != null) {
            tmp = curr.next;
            curr.next = secondHalf;
            secondHalf = curr;
            curr = tmp;
        }

        // 3) Cut first half to prevent cycles
        slow.next = null;

        // 4) Merge: first half + popped nodes
        curr = head;
        while (secondHalf!=null) {
            ListNode backNext = secondHalf.next;
            ListNode nextFront = curr.next;

            curr.next = secondHalf;
            curr.next.next = nextFront;
            curr = nextFront;
            secondHalf = backNext ;
        }
    }
}