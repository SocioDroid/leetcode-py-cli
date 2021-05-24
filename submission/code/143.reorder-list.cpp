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
    void reorderList(ListNode* head) {
        ListNode* temp = head;
        ListNode* fastp = head;
        
        while(fastp != NULL && fastp->next != NULL){
            temp = temp->next;
            fastp = fastp->next->next;
        }
        fastp = head;
        temp = reverse(temp);
        ListNode*  temp2;
        while(temp->next != NULL)
        {
            temp2=fastp->next;     
            fastp->next = temp;     
            temp = temp->next;      
            fastp->next->next = temp2;
            fastp = fastp->next->next;
        }
    }
    
    ListNode* reverse(ListNode* head) {
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