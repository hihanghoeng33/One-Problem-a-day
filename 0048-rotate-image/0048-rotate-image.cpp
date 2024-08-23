class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int len = matrix.size();
        int i=0, j=0;
        for (i = 0; i < len; i++)
        {
            for(j = i+1; j < len; j++){
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
        for(int i=0;i<len;i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};