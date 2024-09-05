class Solution {
public:
    int subtractProductAndSum(int n) {
        int product=1, sum=0;
        int okegas=n;
        while(1){
            okegas = n%10;
            n=n/10;
            sum+=okegas;
            product*=okegas;
            if(n<=0){break;}
        }
        return product-sum;
    }
};