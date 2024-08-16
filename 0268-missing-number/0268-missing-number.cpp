class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i=0, j=0;
        int maks = INT_MIN;
        int len1 = nums.size();
        vector<int> compared;
        for (i = 0; i <= len1; i++)
        {
            compared.push_back(i);
        }
        int len2 = compared.size();
        int check = 0;
        for (i = 0; i < len2; i++)
        {
            check = 0;
            for (j = 0; j < len1; j++)
            {
                if(compared[i]==nums[j]){
                    check = 1;
                    break;
                }
            }
            if(check==0){
                return compared[i];
            }
            
        }
        
        return compared == nums;
    }
};
