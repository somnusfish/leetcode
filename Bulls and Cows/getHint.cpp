class Solution {
public:
    string getHint(string secret, string guess) {
        int originCount[10] = {0};
        int guessCount[10] = {0};
        int bulls = 0;
        int cows = 0;
        for(int i=0; i<secret.size(); i++){
            if(secret[i] == guess[i]){
                bulls ++;
            }
            else{
                originCount[secret[i]-'0']++;
                guessCount[guess[i]-'0']++;
            }
        }
        for(int i=0; i<10; i++){
            cows += min(originCount[i], guessCount[i]);
        }
        string s = to_string(bulls) + "A" + to_string(cows) + "B";
        return s;
    }
};
