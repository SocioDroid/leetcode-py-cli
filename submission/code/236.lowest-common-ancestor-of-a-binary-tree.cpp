/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    bool find(TreeNode* node, TreeNode* to_find, vector<TreeNode*>& v){
        if(!node)
            return false;
        
        v.push_back(node);
        
        if(node->val == to_find->val)
            return true;
        
        if(find(node->right, to_find, v) || find(node->left, to_find, v))
            return true;
        
        v.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> vp, vq;
        
        find(root, p, vp);
        find(root, q, vq);
        
        TreeNode* temp = NULL;
        int i=0;   
        
        while(vp.size() > i && vq.size() > i)
        {
            if(vp[i] == vq[i])
                temp = vp[i];
            else
                break;
            i++;
        }
        return temp;
    }
};