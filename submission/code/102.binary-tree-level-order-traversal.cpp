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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root)
            return res;
    
            
        queue<TreeNode*> q;
        q.push(root);
        int count = 0;
        int pow = 1;
        TreeNode* node;
        res.push_back({});
        q.push(NULL);
        while(true){
            node = q.front();
            q.pop();
            if(node)
            {
                res.back().push_back(node->val);
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }else{
                if(q.empty())
                    return res;
                q.push(NULL);
                res.push_back({});
            }
        }
        // while(res.back().size() == 0)
        //     res.pop_back();
        return res;
    }
};