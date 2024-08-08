class Solution {
public:
    bool checkRecord(string s) {
        int countA=0, countL=0, checkL=1;
        int eligible = 1;
        for(char c:s){
            if(c=='L'){
                if(checkL==1){
                    countL++;
                }else{
                    checkL=1;
                    countL=1;
                }
                if(countL>=3) return false;
            }else{
                checkL=0;
                if(c=='A'){
                    countA++;
                }
            }
            cout << countA << " " << countL << endl;
        }
        
        if(countA>=2 || countL>=3){eligible = 0;}
        return eligible==1;
    }
};