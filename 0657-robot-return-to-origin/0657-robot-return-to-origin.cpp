class Solution {
public:
    bool judgeCircle(string moves) {
        int U = 0, D = 0, L = 0, R = 0;
        for (char c : moves)
        {
            cout << U << D << L << R << endl;
            if(c=='U'){
                U++;
                if(D>=1){
                    U--;
                    D--;
                }
            }else if(c=='D'){
                D++;
                if(U>=1){
                    U--;
                    D--;
                }
            }else if(c=='R'){
                R++;
                if(L>=1){
                    R--;
                    L--;
                }
            }else if(c=='L'){
                L++;
                if(R>=1){
                    R--;
                    L--;
                }
            }
        }
        return (R<=0 && L<=0 && U<=0 && D<=0);
    }
};
