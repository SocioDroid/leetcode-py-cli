class Solution {
public:
    
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<vector<int>> graph(n+1, vector<int>(n+1, 0));
        for(auto ls : trust)
            graph[ls[0]][ls[1]] = 1;
       
        int i;
        
        for(i=1; i<=n; i++){
            int count = 0;    
            for(int j=1; j<=n; j++){
                if(graph[j][i])
                    count++;
                
            }
            if((count == n-1) && (find(graph[i].begin(), graph[i].end(), 1) == graph[i].end()))
                return i;
        }
        return -1;
    }
};