class Solution {
public:
    int candy(vector<int>& ratings) {
        if(ratings.size()==0){
            return 0;
        }
        if(ratings.size()==1){
            return 1;
        }
        int * candyArray = new int[ratings.size()];
        int peak = 0;
        int nadir = 0;
        candyArray[0] = 1;
        for(int i=0; i<ratings.size(); i++){
            if(ratings[i] == ratings[i-1]){
                candyArray[i] = 1;
            }
            else if(ratings[i] > ratings[i-1]){
                candyArray[i] = candyArray[i-1]+1;
            }
            else{
                candyArray[i] = candyArray[i-1]-1;
            }
            
            if(((i!=ratings.size()-1) && (ratings[i]<=ratings[i+1]))
                || (i==ratings.size()-1)){
                int j=i;
                int shift = 1-candyArray[i];
                while((j>=0) && (ratings[j] < ratings[j-1])){
                    candyArray[j] += shift;
                    j--;
                }
                if(shift>0){
                    candyArray[j] += shift;
                }
            }
        }
        int sum = 0;
        for(int i=0; i<ratings.size(); i++){
            cout << candyArray[i] << " ";
            sum += candyArray[i];
        }
        
        return sum;
    }
};
