class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> s;
        for(string w:strs){
            string sorted = w;
            sort(sorted.begin(), sorted.end());
            s[sorted].push_back(w);
        }
        vector<vector<string>> res;
        for(auto& g:s){
            res.push_back(g.second);
        }
        return res;
    }
};