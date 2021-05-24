class Solution {
public:
    
    vector<vector<int>> dir = {{0,1},{-1,0}, {1,0},{0,-1}};
    int numIslands(vector<vector<char>>& grid) {
        int n = grid[0].size();
        int m = grid.size();
        
        vector<vector<bool>> visited(m, vector<bool>(n,false));
        int count = 0;
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(!visited[i][j] && grid[i][j] == '1'){
                    dfs(grid, visited, i, j);
                    count++;
                    // cout<<"For i , j : "<<i<<" , "<<j<<endl;
                    // for(auto k: visited){
                    //     for(auto l:k){
                    //         cout<<l<<"\t";
                    //     }
                    //     cout<<endl;
                    // }
                }
            }
        }
        return count;
    }
    

    
    void dfs(vector<vector<char>>& isConnected, vector<vector<bool>>& visited, int i, int j){
        int n = isConnected[0].size();
        int m = isConnected.size();
        if(i < 0 || j < 0 || j>=n || i>=m)
            return;
        
        if(visited[i][j] || isConnected[i][j] == '0')
            return;
        
        visited[i][j] = true;
                
        for(auto k: dir){
            dfs(isConnected, visited, i-k[0], j-k[1]);
        }
    }
};

 
 
 
 
 
 
 