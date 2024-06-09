class Solution {
public:
    int reverse(int x) {
        long res = 0;
        while(x){
            res = res*10 + x%10;
            x/=10;
        }
        if(res>2147483647 || res<-2147483648){
            return 0;
        }
        return res;
    }
};