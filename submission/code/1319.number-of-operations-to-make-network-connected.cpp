class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n-1)
            return -1;
        
        vector<int> visited(n, false);
        int count = 0;
        
        vector<vector<int>> graph = createGraph(connections, n);
        auto startNode = find(visited.begin(), visited.end(), false);
        while(startNode != visited.end()){
            dfs(graph, visited, startNode - visited.begin());
            count++;
            startNode = find(visited.begin(), visited.end(), false);
        }
        return count-1;
    }
    
    vector<vector<int>> createGraph(vector<vector<int>> connections, int n){
        vector<vector<int>> graph(n);
        for(auto connection : connections){
            graph[connection[0]].push_back(connection[1]);
            graph[connection[1]].push_back(connection[0]);
        }
        return graph;
    }
        
    void dfs(vector<vector<int>>& isConnected, vector<int>& visited, int node){
        if(visited[node])
            return;
        
        visited[node] = true;
                
        for(auto i : isConnected[node])
            if(!visited[i] && i!= node)
               dfs(isConnected, visited, i);
    }
};