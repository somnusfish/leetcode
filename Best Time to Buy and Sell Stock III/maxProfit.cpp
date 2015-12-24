class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1){
            return 0;
        }
        int * left = new int[prices.size()];
        int * right = new int[prices.size()];
        
        int profit = 0;
        int minPrice = prices[0];
        int maxPrice = prices[prices.size()-1];
        
        left[0] = 0;
        for(int i=1; i<prices.size(); i++){
            if(prices[i]-minPrice > profit){
                profit = prices[i] - minPrice;
            }
            if(prices[i] < minPrice){
                minPrice = prices[i];
            }
            left[i] = profit;
        }
        profit = 0;
        right[prices.size()-1] = 0;
        for(int i=prices.size()-2; i>=0; i--){
            cout<< i<< endl;
            if(maxPrice - prices[i] > profit){
                profit =maxPrice-prices[i];
            }
            if(prices[i] > maxPrice){
                maxPrice = prices[i];
            }
            right[i] = profit;
        }
        int max = left[prices.size()-1];
        for(int i=0; i<prices.size()-1; i++){
            if(left[i] + right[i] > max){
                max = left[i] + right[i+1];
            }
        }
        return max;
    }
};
