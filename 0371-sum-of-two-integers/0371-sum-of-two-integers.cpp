class Solution {
public:
    int getSum(int a, int b) {
        int ok=a;
        while((a&b)!=0){
            ok=a;
            a=a^b;
            b=(ok&b) << 1;
        }
        return a|b;
    }
};