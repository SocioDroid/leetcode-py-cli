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
    
    TreeNode* build(int& preIndex, int inStart, int inEnd, vector<int>& preorder, vector<int>& inorder){
        if(preIndex > preorder.size()-1 || inStart > inEnd)
            return NULL;
        
        TreeNode* node = new TreeNode(preorder[preIndex]);
        
        int inIndex = inStart;
        for(; inIndex<inEnd; inIndex++)
        {
            if(node->val == inorder[inIndex])
                break;
        }
        preIndex++;
        node->left = build(preIndex, inStart, inIndex-1, preorder, inorder);
        node->right = build(preIndex, inIndex+1, inEnd, preorder, inorder);
        
        return node;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int temp = 0;
        return build(temp, 0, inorder.size()-1, preorder, inorder);
    }
};