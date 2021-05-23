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

struct comp{
    bool operator()(const ListNode* lhs, const ListNode* rhs)
    {
        return lhs->val > rhs->val;
    }
};
class Solution {
public:

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, comp> p;
        
        for(ListNode* node : lists)
            if(node)
                p.push(node);
            
        
        ListNode* head = new ListNode();
        ListNode* temp = head;
        while(!p.empty()){
            temp->next = p.top();
            if(p.top()->next)
                p.push(p.top()->next);
            cout<<p.top()->val<<"\t";
            p.pop();
            temp = temp->next;
        }
        return head->next;
    }
};