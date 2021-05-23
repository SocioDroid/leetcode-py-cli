class Solution {
public:
    set<int> visited;
    map<int, set<int>> graph;
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        for(auto edge: edges){
            visited.clear();
            int source = edge[0];
            int target = edge[1];
            
            if(graph.find(source) != graph.end() && graph.find(target) != graph.end() && isCycle(source, target))
                return edge;
            graph[source].insert(target);
            graph[target].insert(source);
            
        }
        return {};
    }
    
    bool isCycle(int source, int target){
        if(visited.find(source) != visited.end())
            return false;
        visited.insert(source);
        if(source == target) 
            return true;
        for (auto node : graph[source])
            if(isCycle(node, target))
                return true;
        return false;
    }
};