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
    
    void inorder(TreeNode* root, vector<int>& v)
    {
        if(!root)
            return;
        inorder(root->left, v);
        v.push_back(root->val);
        inorder(root->right, v);
    }
    bool isValidBST(TreeNode* root) {
        vector<int> v;
        inorder(root, v);
        for(int i=1; i<v.size(); i++)
            if(v[i-1]>=v[i])
                return false;
        
        return true;
//         if(root->left && root->right)
//         {
//             if(root->left->val < root->val && root->right->val > root->val)
//                 return isValidBST(root->left) && isValidBST(root->right);
            
//             return false;
//         }
//         else if(root->left)
//         {
//             if(root->left->val < root->val)
//                 return isValidBST(root->left);
            
//             return false;
//         }
//         if(root->right)
//         {
//             if(root->right->val > root->val)
//                 return isValidBST(root->right);
            
//             return false;
//         }
//        return true;
    }
};