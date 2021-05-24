class Solution {
public:
    int minsum = INT_MAX;
    int solve(vector<vector<int>>& grid, int m, int n, int sum, vector<vector<int>>& dp){
        if(m == grid.size() || n==grid[0].size()) {
            return 0;
        }
        
        if(m == grid.size()-1 && n==grid[0].size()-1) {
            sum = sum+grid[m][n];
            minsum = min(sum, minsum);
            dp[m][n] = min(dp[m][n], sum);
            return sum;   
        }
        
        sum = sum+grid[m][n];
        dp[m][n] = min(dp[m][n], sum);
        solve(grid,m+1,n, sum, dp);
        solve(grid, m, n+1, sum, dp);
        
        if(m == 0 && n == 0)
            dp[m][n] = grid[m][n];
        else if(m == 0)
            dp[m][n] = dp[m][n-1];
        else if(n == 0)
            dp[m][n] = dp[m-1][n];
        else
            dp[m][n] = min(dp[m-1][n], dp[m][n-1]);
        
        return grid[m][n]+ dp[m][n];
    }    
    
    void print(vector<vector<int>> dp){
        for(auto i : dp){
            for(auto j : i){
                cout<<j<<" ";
            }
            cout<<endl;
        }
        
    }
    
    void solveDP(vector<vector<int>>& grid, vector<vector<int>>& dp){
        int m = grid.size();
        int n = grid[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i == 0 && j == 0)
                    dp[i][j] = grid[i][j];
                else if(i == 0)
                    dp[i][j] = grid[i][j] + dp[i][j-1];
                else if(j == 0)
                    dp[i][j] = grid[i][j] + dp[i-1][j];
                else
                    dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), INT_MAX));
        int sum = 0;
        // solve(grid, 0, 0, sum, dp);
        solveDP(grid, dp);
        // print(dp);
        return dp[grid.size()-1][grid[0].size()-1];
        
    }
};