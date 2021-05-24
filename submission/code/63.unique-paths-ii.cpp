class Solution {
public:
    
    int count = 0;
    bool solve(vector<vector<int>>& obstacleGrid, int bottom, int right){
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        // cout<<"bottom : "<<bottom<<"\t"<<right<<endl;
        if(bottom == m || right == n)
            return true;
          
        if(obstacleGrid[bottom][right])
            return false;
        
        if(bottom == m-1 && right == n-1){
            count++;
            return true;
        }
        solve(obstacleGrid, bottom, right+1);
        solve(obstacleGrid, bottom+1, right);
        return true;
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        // solve(obstacleGrid, 0,0);
        
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        int dp[m][n];
        
        memset(dp, 0, sizeof(dp));
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                
                if(obstacleGrid[i][j])
                    continue;
                
                if(i == 0 && j == 0)
                    dp[i][j] = 1;
                
                
                else if(i==0)
                    dp[i][j] += dp[i][j-1];
                
                else if(j==0)
                    dp[i][j] += dp[i-1][j];
            
                else
                    dp[i][j] += dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};