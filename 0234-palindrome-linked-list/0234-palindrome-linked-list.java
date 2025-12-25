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
    public boolean isPalindromeUsingList(ListNode head) {
        List<Integer>lst = new ArrayList<>();
        ListNode curr = head;
        while(curr != null){
            lst.add(curr.val);
            curr = curr.next;
        }
        curr = head;
        int sz = lst.size();
        boolean palin = true;
        if(sz <= 1) return palin;

        while(curr!=null){
            Integer val = lst.get(sz-1);
            sz--;
            if(val != curr.val)
            {
                palin = false;
                break;
            }
            curr = curr.next;
        }
        return palin;
        
    }

     public boolean isPalindromeUsingStack(ListNode head) {
        Stack<Integer> st = new Stack<>();
        ListNode curr = head;
        while(curr != null){
            st.push(curr.val);
            curr = curr.next;
        }
        curr = head;
        boolean palin = true;
        while(curr!=null){
            Integer val = st.pop();
            if(val != curr.val)
            {
                palin = false;
                break;
            }
            curr = curr.next;
        }
        return palin;
     }

     public ListNode reverseNodes(ListNode head){
        ListNode rev = null , tmp = null;
        ListNode curr = head;
        while(curr!=null){
            tmp = curr.next;
            curr.next = rev;
            rev = curr;
            curr = tmp;
        }
        return rev;
     }

     public boolean isPalindrome(ListNode head) {
        if(head==null || head.next==null)
            return true;
        ListNode slow = head , fast = head;

        // find middle, slow will be at middle
        while(fast!=null && fast.next!=null){
            slow = slow.next;
            fast = fast.next.next;
        }

        // If odd length, skip the middle node
        if(fast!=null)
            slow = slow.next;

        ListNode secondHalfReversed = reverseNodes(slow);

        ListNode firsthalf = head;
        while(secondHalfReversed!=null){
            if(firsthalf.val != secondHalfReversed.val)
            {
                return false;
            }
            firsthalf = firsthalf.next;
            secondHalfReversed = secondHalfReversed.next;
        }
        return true;

     }
}