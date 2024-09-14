class Solution {
public:
    int hammingWeight(int n) {
        int count=0;
        int remain;
        while(n>0){
            remain = n%2;
            n = n/2;
            if(remain==1){
                count++;
            }
        }
        return count;
    }
};