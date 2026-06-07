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
    public ListNode swapPairsRecursive(ListNode head) {
        // same as 25. Reverse Nodes in k-Group
        if(head==null) return head;

        // go to the starting node that is the to be reversed
        ListNode tail = head;
        for(int i=0; i<2; i++){
            if(tail==null) return head;
            tail = tail.next;
        }
        ListNode newhead = reverse(head,tail); // reversed head
        head.next = swapPairs(tail); // stich next reversed part

        return newhead;
        
    }
    public ListNode reverse(ListNode curr, ListNode end){
        ListNode tmp = null;
        while(curr != end){
            ListNode nextNode = curr.next;
            curr.next = tmp;
            tmp = curr;
            curr = nextNode;
        }
        return tmp;
    }


    // without recursion,  exchange the nodes itself
    public ListNode swapPairs(ListNode head) {
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode prev = dummy;

        while (prev.next != null && prev.next.next != null) {
            ListNode first = prev.next;
            ListNode second = first.next;

            first.next = second.next;
            second.next = first;
            prev.next = second;

            prev = first;
        }

        return dummy.next;
    }
}