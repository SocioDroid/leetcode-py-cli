class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int index_max[prices.size()];
        index_max[prices.size()-1] = prices.back();
        for(int i=prices.size()-2; i>=0; i--){
            index_max[i] = max(index_max[i+1], prices[i]);
        }
        int max_profit=0;
        for(int i=0; i<prices.size(); i++){
            if(max_profit < index_max[i]-prices[i])
                max_profit = index_max[i]-prices[i];
        }
        return max_profit;
    }
};