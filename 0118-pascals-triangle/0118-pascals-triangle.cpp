class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows == 0) 
            return {};
        else if(numRows == 1)
            return {{1}};
        vector<vector<int>> prev = generate(numRows-1);
        vector<int> newRows(numRows, 1);
        for(int i=1;i<numRows-1;i++){
            newRows[i] = prev.back()[i-1] +  prev.back()[i];
        }

        prev.push_back(newRows);
        return prev;
    }
};