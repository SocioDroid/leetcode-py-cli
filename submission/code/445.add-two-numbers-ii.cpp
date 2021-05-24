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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverse(l1);
        l2 = reverse(l2);
        ListNode* ans = NULL;
        int carry = 0;
        int res;
        
        ans = new ListNode(0);
        ListNode* ls = ans;
        while(l1 != NULL && l2 != NULL)
        {
            res = l1->val + l2->val + carry;
            carry = 0;
            if(res > 9)
                carry = 1;
            ans->next = new ListNode(res%10);
            l1 = l1->next;
            l2 = l2->next;
            ans = ans->next;
            cout<<ans->val<<"  "<<res%10<<endl;
        }
        
        while(l1)
        {
            
            res = l1->val + carry;
            carry = 0;
            if(res > 9)
                carry = 1;
            ans->next = new ListNode(res%10);
            l1 = l1->next;
            ans = ans->next;
            cout<<ans->val<<"  "<<res%10<<endl;
        }
        while(l2)
        {
            res = l2->val + carry;
            carry = 0;
            if(res > 9)
                carry = 1;
            ans->next = new ListNode(res%10);
            l2 = l2->next;
            ans = ans->next;
            cout<<ans->val<<"  "<<res%10<<endl;
        }
        if(carry)
            ans->next = new ListNode(carry);
        return reverse(ls->next);
    }
    
    ListNode* reverse(ListNode* head)
    {
        ListNode* current = head;
        ListNode* backp = NULL;
        ListNode* frontp = NULL;
        while(current != NULL)
        {
            frontp = current->next;
            current->next = backp;
            backp = current;
            current = frontp;
        }
        return backp;
    }
};