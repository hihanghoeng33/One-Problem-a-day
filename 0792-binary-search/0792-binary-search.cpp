class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len = nums.size();
        int left = 0, right = len-1;
        int i=0;
        while(left<=right){
            if(nums[left] == target){
                return left;
            }else if(nums[right] == target){
                return right;
            }
            left++; right--;
        }
        return -1;
    }
};