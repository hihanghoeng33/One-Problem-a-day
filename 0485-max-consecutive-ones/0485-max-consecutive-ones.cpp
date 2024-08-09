class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count=0;
        vector<int> gas;
        while (!nums.empty())
        {
            if(nums.back()==1){
                count++;
            }else{
                count=0;
            }
            gas.push_back(count);
            nums.pop_back();
        }
        int maks = INT_MIN;
        for (int i = 0; i < gas.size(); i++)
        {
            if(maks<gas[i])maks = gas[i];
        }
        
        return maks;
    }
};