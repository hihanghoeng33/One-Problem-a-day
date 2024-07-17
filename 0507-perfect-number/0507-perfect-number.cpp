class Solution {
public:
    bool checkPerfectNumber(int num) {
        int div = 1, total=0, baru = 0;
        baru+=num;
        while(div<baru){
            if(baru%div==0){
                    total+=div;
            }
            div++;
        }
        return total==num;
    }
};