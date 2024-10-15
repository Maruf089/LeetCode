// https://leetcode.com/problems/palindrome-linked-list

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int val=0, ListNode next=null) {
 *         this.val = val;
 *         this.next = next;
 *     }
 * }
 */
public class Solution {
    public bool IsPalindrome(ListNode head) {
        
        string s = "";
        while(head != null)
        {
            s += head.val;
            head = head.next;
        }
        
        string ss = "";
        for(int i=s.Length-1;i>=0;i--)
            ss += s[i];
        
        return s==ss;
        
    }
}