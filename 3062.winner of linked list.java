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
    public String gameResult(ListNode head) {
        int odd = 0 , even = 0;
        while(head != null and head.next!=null){
            if(head.val > head.next.val)
                even++;
            else odd++;
            head = head.next.next;
        }
        if(even > odd) return "Even";
        else if(even < odd) return "Odd";
        else return "Tie";
    }
}
        