class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> store;
        int i=0, j=0;
        int len = nums.size();
        int curr = 0, count = 0;
        while(i<len){
            count=0;
            curr = nums[i];
            j=0;
            while(j<len){
                if(i!=j && curr > nums[j]){
                    count++;
                }
                j++;
            }
            i++;
            store.push_back(count);
        }
        return store;
    }
};