class Solution {
public:
    int getLucky(string s, int k) {
        string baru;
        for(char c:s){
            int number;
            if(c>='a' && c<='z'){
                number=c-'a' + 1;
            }else if(c>='A' && c<='Z'){
                number=c-'A' + 1;
            }
            baru+=to_string(number);
        }  
        int sum = 0; 
        while (k>0)
        {
            sum = 0;
            for(char c:baru){
                sum+=c-'0';
            }
            baru=to_string(sum);
            k--;
        }
        return sum;
    }
};
