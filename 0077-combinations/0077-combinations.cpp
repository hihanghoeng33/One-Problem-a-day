class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> hehe;
        vector<int> oke;
        backTrack(n, k, 1, oke, hehe);
        return hehe;
    }
    void backTrack(int n, int k, int start, vector<int>&oke, vector<vector<int>>&hehe){
        if(oke.size()==k){
            hehe.push_back(oke);    
            return;
        }
        for(int i=start;i<=n;i++){
            oke.push_back(i);
            backTrack(n, k, i+1, oke, hehe);
            oke.pop_back();
        }
    }
};