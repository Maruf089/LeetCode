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
    public int getDecimalValue(ListNode head) {
        int count = 0;
        ListNode tail = head;
        while(tail != null){
            count++;
            tail = tail.next;
        }
        count--;
        int res = 0;
        while(head != null){
            if(head.val==1){
                res |= (1 << count);
            }
            head = head.next;
            count--;
        }
        return res;
    }
}