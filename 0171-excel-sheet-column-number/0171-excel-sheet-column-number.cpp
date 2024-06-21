class Solution {
public:
    int titleToNumber(string columnTitle) {
        int total = 0, index = columnTitle.size() - 1;
        for(auto i : columnTitle){
            total+=(i-64) * pow(26, index--);
        }return total;
    }
};