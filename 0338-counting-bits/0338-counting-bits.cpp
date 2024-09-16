class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> store;
        int pushed=0;
        for(int i=0;i<=n;i++){
            pushed = hammingWeight(i);
            store.push_back(pushed);
        }
        return store;
    }
private:
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