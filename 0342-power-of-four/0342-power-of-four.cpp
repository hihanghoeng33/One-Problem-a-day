class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0){return false;}
        int rem = n%4;
        while(n!=1){
            rem = n%4;
            if(rem!=0){
                return false;
            }
            n = n/4;
        }
        return true;
    }
};