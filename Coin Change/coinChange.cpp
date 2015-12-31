class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        if(0 == amount){
            return 0;
        }
        vector<int> count(amount+1, -1);
        for(int i=0; i<coins.size(); i++){
            if(coins[i] <= amount){
                count[coins[i]] = 1;
                if(count[amount] > 0){
                    return count[amount];
                }
            }
        }
        for(int i=1; i<=amount; i++){
            if(count[i] > 0){
                for(int j=0; j<coins.size(); j++){
                    int val = i+coins[j];
                    if((val <= amount) && ((-1 == count[val]) || (count[val] > count[i]+1))){
                        count[val] = count[i]+1;
                    }
                }
            }
        }
        return count[amount];
    }
};
