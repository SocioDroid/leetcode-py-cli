class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<int> visited(isConnected.size());
        int count = 0;
        
        auto startNode = find(visited.begin(), visited.end(), false);
        
        while(startNode != visited.end()){
            queue<int> q;
            q.push(startNode - visited.begin());
            
            while(!q.empty()){
                int node = q.front();
                q.pop();
                // cout<<"BFS for : "<<node<<endl;
                
                visited[node] = true;
                
                for(int i=0; i<isConnected[0].size(); i++)
                    if(isConnected[node][i] == 1 && !visited[i] && i!= node)
                        q.push(i);
            }
            
            // for(auto k:visited)
            //     cout<<k<<"\t";
            // cout<<endl;
            // cout<<endl;
            
            count++;
            startNode = find(visited.begin(), visited.end(), false);
        }
        return count;
    }

};