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
    
    TreeNode* findMin(TreeNode* node){
        while(node->left != NULL) 
            node = node->left;
        return node;
    }
    
    TreeNode* del(TreeNode* node, int key){
        if(!node)
            return NULL;
        if(node->val > key)
            node->left = del(node->left, key);
        
        else if(node->val < key)
            node->right = del(node->right, key);

        else if(node->val == key){
            if(node->left == NULL && node->right == NULL)\
                node = NULL;
            else if(node->left == NULL)
                node = node->right;
            else if(node->right == NULL)
                node = node->left;
            else{
                TreeNode* temp = findMin(node->right);
                node->val = temp->val;
                node->right = del(node->right, temp->val);
            }
        }
        return node;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        return del(root, key);
    }
};