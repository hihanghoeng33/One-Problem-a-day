class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if(original.size()!=m*n){
            return {};
        }
        vector<vector<int>> modified (m, vector<int>(n));
        int i=0, j=0;
        int len = original.size(), index = 0;
            for(i=0;i<m;i++){
                for(j=0;j<n;j++){
                    modified[i][j] = original[i*n+j];
                }

            }

        return modified;
    }
};