class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        int i=0, j=0, total = 0;
        vector<int> freq;
        vector<pair<int, int>> paired_nums;
        for (i = 0; i < nums.size(); i++)
        {
            total = 0;
            for(j=0;j<nums.size();j++)
            {
                if(nums[i]==nums[j]){total+=1;}
            }
            freq.push_back(total);
        }
        for (i = 0; i < nums.size(); i++)
        {
            paired_nums.push_back(make_pair(nums[i], freq[i]));
        }
        sort(paired_nums.begin(), paired_nums.end(), [](pair<int, int>& a, pair<int, int>& b) {
            return (a.second==b.second) ? a.first > b.first : a.second < b.second;
        });
        vector<int> sorted;
        for (const auto a : paired_nums)
        {
            sorted.push_back(a.first);
        }
        return sorted;
    }
};