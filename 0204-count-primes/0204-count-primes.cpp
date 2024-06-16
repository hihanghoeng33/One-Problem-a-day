class Solution {
public:
    int countPrimes(int n) {
        if(n<=2){
            return 0;
        }
        int  i=2, j, count = 0;
        vector<int> isPrime(n, 1);
        isPrime[0] = 0, isPrime[1] = 0; 

        while(i*i<n){
            if(isPrime[i]){
                for(j=i*i;j<n;j+=i){
                    isPrime[j] = 0;
                }
            }
            i++;
        }
        for(i=2;i<n;i++){
            if(isPrime[i]){
                count++;
            }
        }
        return count;
    }
};