/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode*> pv,qv;
        pv.push(p);
        qv.push(q);
        TreeNode *ptemp, *qtemp;
        while(!pv.empty() && !qv.empty())
        {
            ptemp = pv.front();
            qtemp = qv.front();
            pv.pop();
            qv.pop();
            if(ptemp == NULL && qtemp == NULL)
                continue;
            else if(ptemp == NULL && qtemp != NULL || ptemp != NULL && qtemp == NULL)
                return false;
                
            if(ptemp->val != qtemp->val)
                return false;
            // if(ptemp->left != NULL)
                pv.push(ptemp->left);
                
            // if(ptemp->right != NULL)
                pv.push(ptemp->right);
                
            // if(qtemp->left != NULL)
                qv.push(qtemp->left);
                
            // if(qtemp->right != NULL)
                qv.push(qtemp->right);
            
        }
        cout<<pv.size()<<"           "<<qv.size();
        if(pv.empty() && qv.empty())
            return true;
        return false;
        
    }
};