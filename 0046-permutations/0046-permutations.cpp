class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        permutation(nums, res, 0);
        return res;
    }
private:
    void permutation(vector<int>& nums, vector<vector<int>>& res, int r){
        if(r==nums.size()){
            res.push_back(nums);
            return;
        }
        for(int i=r;i<nums.size();i++){
            swap(nums[i], nums[r]);
            permutation(nums, res, r+1);
            swap(nums[i], nums[r]);
        }
    }
};