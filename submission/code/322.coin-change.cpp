class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());  
        
        vector<int> dp(amount+1, amount+1);
        dp[0] = 0;
        for(auto j : coins){
            for(long i = j; i<=amount; i++){
                dp[i] = min(dp[i], 1 + dp[i-j]);
            }
        }
        
        return dp[amount] == amount+1 ? -1 : dp[amount];
    }
};