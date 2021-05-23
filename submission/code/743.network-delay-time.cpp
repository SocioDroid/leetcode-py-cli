class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<int>> graph(n+1, vector<int>(n+1, -1));
        
        bool flag = false;
        for(auto time: times)
        {
            graph[time[0]][time[1]] = time[2];
            if(time[0] == k)
                flag = true;
        }
        
        if(!flag)
            return -1;
        vector<int> distance = dijkstra(graph, k);
      
        if(distance.size() == 1)
            return -1;
        
        int max_m = INT_MIN;
        
        for(auto i : distance)
        {
            if(i != INT_MAX)
                max_m = max(i, max_m);
        }
        
        return max_m;
    }
    
    vector<int> dijkstra(vector<vector<int>> graph, int source){
        vector<int> visited(graph.size(), 0);
        
        vector<int> distance(graph.size(), INT_MAX);
        
        distance[source] = 0;
        
        int min_dist = INT_MAX;
        
        cout<<"All Initialized well"<<endl;
        while(find(visited.begin()+1, visited.end(), 0) != visited.end()){
            int node = -1;
            min_dist = INT_MAX;
            for(int i=1; i<visited.size(); i++){
                // cout<<"Found node " <<i<<" : "<<(visited[i] == 0)<<endl;
                if(min_dist > distance[i] && visited[i] == 0){
                        min_dist =  distance[i];
                        node = i;
                }
            }
            
            cout<<"Found node after : "<<node<<endl;
            
            if(node == -1 || distance[node] == INT_MAX)
                return {-1};
            visited[node] = 1;
            
            cout<<"Visited \t ";
            for(auto visit : visited){
                cout<<visit<<"\t";
            }
            cout<<endl;
            // cout<<"Debug point 1 : "<<node<<endl;

            for(int j=1; j<graph[node].size(); j++)
            {
                // cout<<"Iteration : "<<j<<endl;

                if(graph[node][j] != -1 && !visited[j])
                    distance[j] = min(distance[j], distance[node]+graph[node][j]);
            }
            // cout<<"Debug point : "<<node<<endl;

        }
        return distance;
    }
    
};