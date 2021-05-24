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
    
     int depth(TreeNode* node){
        if(!node)
            return 0;
         int left = depth(node->left);
         int right =  depth(node->right);
         if(left==0 || right==0)
            return 1+max(left,right);
         
        return 1+min(left,right);
        // return min() + 1, + 1);
    }
    
    int minDepth(TreeNode* root) {
     return depth(root);   
    }
};