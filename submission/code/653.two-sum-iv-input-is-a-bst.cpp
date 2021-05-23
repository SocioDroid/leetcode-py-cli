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
//     vector<TreeNode*> convert(TreeNode* root){
//         if(!root)
//             return NULL;
//         vector<TreeNode*> left = convert(root->left);
//         vector<TreeNode*> right = convert(root->right);
        
//     }
    void inorder(TreeNode* root, vector<int>& v){
        if(root!=NULL)
        {
            if(root->left != NULL)
                inorder(root->left, v);
            v.push_back(root->val);
            if(root->right != NULL)
                inorder(root->right, v);    
        }
    }
    
    bool findTarget(TreeNode* root, int k) {
        vector<int> v;
        inorder(root, v);
        
        int left = 0, right = v.size()-1;
        while(left < right)
        {
            int res = v[left] + v[right];
            if(res == k)
                return true;
            else if(res < k)
                left++;
            else
                right--;
        }
        return false;
    }
};