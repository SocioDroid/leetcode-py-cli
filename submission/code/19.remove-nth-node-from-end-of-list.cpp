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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;

        if(head->next == NULL)
            return head->next;
            
        
        ListNode* back = head;
        bool flag = false;
        int ncpy = n;
        int c = 1;
        while(temp->next != NULL)
        {
            if(n > 0)
                n--;
            else
            {
                flag = true;
                back=back->next;
            }
            c++;
            temp = temp->next;
        }
        
        cout<<back->val;
        if(ncpy == 1)
            back->next = NULL;
        
        else if(c == ncpy)
            head = head->next;
        else
            back->next = back->next->next;    
        
        return head;
    }
};