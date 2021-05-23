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
    ListNode* reverseList(ListNode* head) {
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