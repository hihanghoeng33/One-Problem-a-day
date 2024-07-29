class Solution {
public:
    vector<int> findPeaks(vector<int>& mountain) {
        vector<int> store;
        int len = mountain.size();
        for(int i=1;i<len-1;i++){
            if(mountain[i]>mountain[i-1] && mountain[i]>mountain[i+1]){
                store.push_back(i);
            }
        }
        return store;
    }
};