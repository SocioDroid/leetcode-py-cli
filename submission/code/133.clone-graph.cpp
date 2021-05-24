/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    
    map<int, Node*> nodes;
    Node* cloneGraph(Node* node) {
        if(!node)
            return NULL;
        set<Node*> visited;
        return dfs(node, visited);
    }
    
    
    Node* dfs(Node* node, set<Node*>& visited){
        if(visited.find(node) != visited.end())
            return nodes[node->val];
        visited.insert(node);
        Node* ans = new Node(node->val);
        nodes[ans->val] = ans;
        // cout<<"For : "<<node->val<<endl;
        for(auto i : node->neighbors){
            ans->neighbors.push_back(dfs(i, visited));
        }
        
        // cout<<"For : "<<ans->val<<"\t";
        // for(auto i : ans->neighbors){
        //     cout<<i->val<<"->";
        // }
        // cout<<endl;
        return ans;
    }
};