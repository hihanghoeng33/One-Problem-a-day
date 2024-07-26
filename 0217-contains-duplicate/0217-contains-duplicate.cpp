class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> dups;
        for(int num : nums){
            if(dups[num]>0){
                return true;
            }
            dups[num]++;
        }
        return false;
    }
};