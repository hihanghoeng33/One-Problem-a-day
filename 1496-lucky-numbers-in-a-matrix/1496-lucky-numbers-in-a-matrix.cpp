
class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int baris = matrix.size();
        int kolom = matrix[0].size();

        vector<int> minim(baris, INT_MAX);
        vector<int> maks(kolom, 0);

        int i, j;
        for(i=0;i<baris;i++){
            for(j=0;j<kolom;j++){
                int res = matrix[i][j];
                minim[i] = min(minim[i], res);
                maks[j] = max(maks[j], res);
            }
        }
        for (i=0;i<baris;i++)
        {
            for(j=0;j<kolom;j++){
                int res = matrix[i][j];
                if(res == minim[i] && res == maks[j]){
                    return{res};
                }
            }
        }
        return{};
    }
};