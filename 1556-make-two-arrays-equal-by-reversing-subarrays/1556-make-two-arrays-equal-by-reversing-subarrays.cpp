class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        sort(target.begin(), target.end());
        sort(arr.begin(), arr.end());
        int i=0, len = target.size();
        for (i = 0; i < len; i++)
        {
            if(target[i]!=arr[i]){
                return false;
            }
        }
        return true;
    }
};