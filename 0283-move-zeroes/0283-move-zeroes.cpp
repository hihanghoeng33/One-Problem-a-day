class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> lesgo;
        int count0 = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){lesgo.push_back(nums[i]);}else{
                count0++;
            }
        }
        nums.clear();
        for (int i = 0; i < count0; i++)
        {
           lesgo.push_back(0);
        }
        for (int i = 0; i < lesgo.size(); i++)
        {
            nums.push_back(lesgo[i]);
        }
        

    }
};
