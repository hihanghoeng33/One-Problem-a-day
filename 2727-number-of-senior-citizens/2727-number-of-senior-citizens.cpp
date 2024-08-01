class Solution {
public:
    int countSeniors(vector<string>& details) {
        int len = details.size();
        int j=0;
        int count=0;
        for(j=0;j<len;j++){
            if( ((details[j][11]-'0')*10 + (details[j][12]-'0')) > 60 ){
                count++;
            }
        }
        return count;
    }
};
