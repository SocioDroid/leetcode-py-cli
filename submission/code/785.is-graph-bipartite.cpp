class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        map<int, int> u_map;
        
        for(int i=0; i<graph.size(); i++){
            if(u_map.find(i) != u_map.end() || graph[i].empty())
                continue;
            
            u_map[i] = 0;
            
            queue<int> q;
            q.push(i);
            
            while(!q.empty()){
                int node = q.front();
                q.pop();
                for(auto adj_node : graph[node]){
                    if(u_map.find(adj_node) != u_map.end()){
                        if(u_map[node] == u_map[adj_node])
                            return false;
                    }
                    else
                    {
                        u_map[adj_node] = !u_map[node];
                        q.push(adj_node);
                    }
                }
                
            }
        }
        return true;
    }
};