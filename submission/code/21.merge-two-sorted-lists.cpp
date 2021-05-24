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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        struct ListNode *node = NULL;
        if(l1 == NULL)
            return l2;
        if(l2 == NULL)
            return l1;
        
        if(l1->val < l2->val)
        {
            node = l1;
            l1 = l1->next;
            node->next = NULL;
        }
        else
        {
            node = l2;
            l2 = l2->next;
            node->next = NULL;
        }
        struct ListNode *temp = node;
        while(l1 && l2)
        {
            if(l1->val <= l2->val)
            {
                temp->next = l1;
                l1 = l1->next;
                temp->next->next = NULL;
            }
            else
            {
                temp->next = l2;
                l2 = l2->next;
                temp->next->next = NULL;
            }
            temp = temp->next;
        }
        if(l1)
            temp->next = l1;
        if(l2)
            temp->next = l2;
        return node;
    }
};