class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<=0){return false;}
        int rem = n%3;
        while(n!=1){
            rem = n%3;
            if(rem!=0){
                return false;
            }
            n = n/3;
        }
        return true;
    }
};