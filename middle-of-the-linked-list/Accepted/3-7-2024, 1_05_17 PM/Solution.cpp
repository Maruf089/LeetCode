// https://leetcode.com/problems/middle-of-the-linked-list

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int count = 1, count1 = 1 ;
        ListNode* root = head;
        while(head->next)
        {
            count++;
            head = head->next;
        };
        if(count==1)
            return head;
        cout << count << endl;

    
        count = count / 2  + 1;

        
        cout << count << endl;

        while(count != count1)
        {
            count1++;
            root = root->next;
        };

        return root;
        
    }
};