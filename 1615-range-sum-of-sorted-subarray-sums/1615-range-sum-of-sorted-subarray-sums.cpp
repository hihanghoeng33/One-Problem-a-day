class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        int i=0,j=0;
        vector<int> store;
        
        int len = nums.size();
        for (i = 0; i < len; i++)
        {
            int sum = 0;
            for (j = i; j < len; j++)
            {
                sum+=nums[j];
                store.push_back(sum);
            }
            
        }
        sort(store.begin(), store.end());
        int totoal = 0;
        int mod = 1000000007;
        for(i=left-1;i<right;i+=1){
            totoal=(totoal+store[i]) % mod;
        }
        return totoal;
    }
};