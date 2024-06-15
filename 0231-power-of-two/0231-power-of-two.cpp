class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0){return false;}
        int rem=n%2;
        while(n!=1){
            rem = n%2;
            n = n/2;
            cout << rem << endl;
            if(rem==1){
                return false;
            } 
        }
        return true;
    }
};