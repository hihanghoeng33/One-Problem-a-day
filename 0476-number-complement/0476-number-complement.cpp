class Solution {
public:
    int findComplement(int num) {
        string okegas;
        int convert = 0;
        while (num>0)
        {        
            convert = num%2;
            string gas = to_string(convert);
            okegas+=gas;
            num=num/2;

        }
        long long base = 1;
        convert = 0;

        string hehe;
        for(char c:okegas){
            if(c=='0'){
                hehe+="1";
            }else{
                hehe+="0";
            }
        }

        for(char c:hehe){
            long long ld = (c-'0');
            convert += ld * base;
            base = base*2;
        }
        return convert;
    }
};