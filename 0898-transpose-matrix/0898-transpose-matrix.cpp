class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int row = 0, col = 0, n=matrix.size(), m=matrix[0].size();
        vector<vector<int>> baru(m, vector<int>(n,0));
        for(row=0;row<matrix.size();row++){
            for(col=0;col<matrix[row].size();col++){
                baru[col][row] += matrix[row][col];
            }
        }
        return baru;
    }
};