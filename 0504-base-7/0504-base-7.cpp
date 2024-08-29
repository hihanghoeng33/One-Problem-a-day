class Solution {
public:
    string convertToBase7(int num) {
        string baru;
        int pos = num;
        int ces=0;
        while(1){
            if(abs(num)<7){
                baru+=to_string(num);
                break;
            }
            ces=abs(num)%7;
            baru+=to_string(ces);
            num=abs(num)/7;

        }
        if(pos<0 && pos<=-7){
            baru+="-";
        }if(pos%10==pos && abs(pos)<7){
            return to_string(pos);
        }
        reverse(baru.begin(), baru.end());
        return baru;
    }
};
