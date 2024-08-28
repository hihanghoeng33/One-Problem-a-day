class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int mark = 0;
        for(int i=0;i<nums.size();i++){
            mark =  abs(nums[i])-1;
            if(nums[mark]>0){
                nums[mark] = -nums[mark];
            }
        }
        vector<int> jir;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                jir.push_back(i+1);
            }
        }
        return jir;
    }
};