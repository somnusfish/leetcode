class Solution {
public:
    int interLine(int A, int B, int C, int D){
        if((B<C) || (D<A)){
            return 0;
        }
        if(C>A){
            if(D>B){
                return B-C;
            }
            else{
                return D-C;
            }
        }
        else{
            if(B>D){
                return D-A;
            }
            else{
                return B-A;
            }
        }
        
    }
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int rec1 = 0;
        int rec2 = 0;
        int inter = 0;
        rec1 = (C-A)*(D-B);
        rec2 = (G-E)*(H-F);
        inter = interLine(A,C,E,G) * interLine(B,D,F,H);
        return rec1+rec2-inter;
    }
};
