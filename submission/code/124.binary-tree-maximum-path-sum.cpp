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
    
    int solve(TreeNode* node, int& res)
    {
        if(!node)
            return 0;
        int left = solve(node->left, res);
        int right = solve(node->right, res);
        
        int temp = max(max(left, right) + node->val, node->val );
        int ans = max(temp, left + right + node->val);
        res = max(res, ans);
        return temp;
    }
    
    int maxPathSum(TreeNode* root) {
        int min = INT_MIN;
        int temp = solve(root, min);
        return min;
    }
};