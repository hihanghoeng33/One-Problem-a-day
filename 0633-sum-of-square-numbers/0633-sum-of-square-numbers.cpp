class Solution {
public:
    bool judgeSquareSum(int c) {
        long long sum = 0;
        long long a=0, b=sqrt(c);
        while(a<=b){
            sum = a*a + b*b;
            if(sum==c){
                return true;
            }else if(sum < c){
                a++;
            }else{
                b--;
            }
        }
        return false;
    }
};