class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int minPrice;
        if(prices.size()<=1){
            return 0;
        }
        minPrice = prices[0];
        for(int i=1; i<prices.size(); i++){
            if(prices[i]-minPrice > profit){
                profit = prices[i] - minPrice;
            }
            if(prices[i] < minPrice){
                minPrice = prices[i];
            }
        }
        return profit;
    }
};
