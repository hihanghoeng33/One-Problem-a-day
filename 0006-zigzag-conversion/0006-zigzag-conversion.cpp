class Solution {
public:
    string convert(string s, int numRows) {
        int len = s.length(), curr = 0;
        int pattern = 2*numRows - 2;
        int flag = 1;
        vector<string> newS(len);
        char str[len];
        if (len == 1 && len < numRows){
            return s;
        }
        for(int i=0; i<len; i++){
            newS[curr].push_back(s[i]);
            if(curr == 0){
                flag = 1;
            }else if(curr == numRows-1){
                flag = -1;
            }
            curr += flag;
        }

        string result;
        for(string &row: newS){
            result += row;
        }
        return result;
    }
};