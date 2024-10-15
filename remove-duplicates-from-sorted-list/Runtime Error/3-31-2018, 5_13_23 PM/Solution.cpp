// https://leetcode.com/problems/remove-duplicates-from-sorted-list

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    
    ListNode* deleteDuplicates(ListNode* head) {
        
        
           ListNode *cur = head;
        if( head == NULL || head->next == NULL)
            return head;
        
   while( cur != NULL || cur->next != NULL){
       
     if(cur->val  == cur->next->val )
       cur->next = cur->next->next;
     else
     cur = cur->next;
   }
   return head;
        
    }
};