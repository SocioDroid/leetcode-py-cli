/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)
            return "x";
        string x = to_string(root->val) + "(" + serialize(root->left) + ")(" + serialize(root->right) + ")"; 
        // cout<<x<<endl;
        return x;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data ==  "x")
            return NULL;
        int start = 0;
        int end = data.find("(");
        int number;
        try{
            number = stoi(data.substr(start, end - start));
        }catch(...)
        {
            return NULL;            
        }    
        TreeNode* n = new TreeNode(number);        
        cout<<"Data   "<<data<<endl;
        start = end+1;
        int count = 0;
        
        for(int i=end; i<data.length(); i++)
        {
            if(data[i] == '(')
                count++;
            else if(data[i] == ')')
            {
                count--;
                if(!count)
               {
                    end = i + 1;
                    break;
                }
            }   
        }
        cout<<"Left data : "<<data.substr(start, end - start)<<endl;
        n->left = deserialize(data.substr(start, end - start));
        
        start = end+1;
        count = 0;
        for(int i=end; i<data.length(); i++)
        {
            if(data[i] == '(')
                count++;
            else if(data[i] == ')')
            {
                count--;
                if(!count)
                {
                    end = i;
                    break;
                }
            }   
        }
        cout<<"Right data: "<<data.substr(start, end - start)<<endl;
        n->right = deserialize(data.substr(start, end - start));
        return n;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));