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
        
        var s = new List<int>();
        while(head != null)
        {
            s.Add(head.val);
            head = head.next;
        }
        
        var ss = new List<int>();
        for(int i=s.Count()-1;i>=0;i--)
            ss.Add(s[i]);
        
        var ans = true;
        for(int i=s.Count()-1;i>=0;i--)
        {
            if(s[i]!=ss[i])
                ans = false;
        }
        
        
        
        return ans;
        
    }
}