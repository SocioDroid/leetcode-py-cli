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
    
    int depth(TreeNode* node)
    {
        if(!node)
            return 0;
        int ldepth = depth(node->left) + 1;
        int rdepth = depth(node->right) + 1;
        // cout<<node->val<<"\t"<<ldepth<<"\t"<<rdepth<<endl;
        return max(ldepth, rdepth);
    }
    
    int maxDepth(TreeNode* root) {
        return depth(root);
    }
};