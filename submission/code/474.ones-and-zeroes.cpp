class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int dp[n+1][m+1];
        memset(dp, 0, sizeof(dp));
        
        for(auto str : strs){
            int ones = 0;
            for(auto i : str){
                if(i == '1') ones++;
            }
            int zeroes = str.length() - ones;
            
            for(int i = n; i>=ones; i--){
                for(int j = m; j>=zeroes; j--){
                    dp[i][j] = max(dp[i][j], 1 + dp[i-ones][j-zeroes]);
                }
            }
        }
    
        for(int i=0; i<n+1; i++){
            for(int j=0; j<m+1; j++){
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        return dp[n][m];
    }
};