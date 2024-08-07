class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        if(s.empty() || g.empty()){
            return 0;
        }
        sort(s.begin(), s.end());
        sort(g.begin(),g.end());
        int store = 0;
        int i=0, j=0;
        while (i<g.size() && j<s.size())
        {
            if(s[j]>=g[i]){
                store++;
                i++;
            }
            j++;
        }
        
        return store;
    }
};
