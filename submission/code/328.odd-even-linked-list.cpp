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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL)
            return head;
        ListNode* begin = head;
        int len = 1;
        while(begin->next != NULL)
        {
            begin = begin->next;
            len++;
        }
        cout<<begin->val<<"  "<<head->val<<endl;
        ListNode* end = begin;  
        begin = head;
        len /= 2;
        cout<<begin->val<<"  "<<end->val<<"   "<<head->val<<endl;
        while(len)
        {
            end->next = begin->next;
            end = end->next;            
            
            begin->next = begin->next->next;
            begin = begin->next;
            len--;
        }
        end->next=NULL;
        cout<<len;
        return head;
        
            
    }
};