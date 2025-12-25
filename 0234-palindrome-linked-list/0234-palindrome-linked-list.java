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
    // public boolean isPalindrome(ListNode head) {
    //     List<Integer>lst = new ArrayList<>();
    //     ListNode curr = head;
    //     while(curr != null){
    //         lst.add(curr.val);
    //         curr = curr.next;
    //     }
    //     curr = head;
    //     int sz = lst.size();
    //     boolean palin = true;
    //     if(sz <= 1) return palin;

    //     while(curr!=null){
    //         Integer val = lst.get(sz-1);
    //         sz--;
    //         if(val != curr.val)
    //         {
    //             palin = false;
    //             break;
    //         }
    //         curr = curr.next;
    //     }
    //     return palin;
        
    // }

     public boolean isPalindrome(ListNode head) {
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
}