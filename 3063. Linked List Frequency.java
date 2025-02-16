    // 3063. Linked List Frequency
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
        public ListNode frequenciesOfElements(ListNode head) {
            Map<Integer,Integer>res = new HashMap<>();
            while(head != null){
                res.merge(head.val, 1, (a,b)-> a+b);
                head = head.next;
            }
            ListNode resHead = new ListNode(0);
            ListNode resTail = resHead;
            for(int val : res.values()){
                resTail.next = new ListNode(val);
                resTail = resTail.next;
            }
            return resHead.next;
        }
    }