class Solution {
public:
    string intToRoman(int num) {
        string roman = "";
        int rem = 0, rem2 = 0, diff = 0;
        while(num){
            if(num/1000 >= 1){
                rem = num/1000;
                for(int i=0; i<rem; i++){
                    roman += "M";
                }
                num%=1000;
            }else{
                if(num >= 500){
                    rem = (num/100)*100;
                    if(rem == 900){
                        roman+="CM";
                    }else{
                        roman += "D";
                        rem2 = (rem-500)/100;
                        cout << rem2 << endl;
                        for(int i=0; i<rem2; i++){
                            roman += "C";
                        }
                    }
                    num%=100;
                }if(num >= 100){
                    rem = (num/100)*100;
                    if(rem == 400){
                        roman+="CD";
                    }else{
                        rem2 = (rem)/100;
                        for(int i=0; i<rem2; i++){
                            roman += "C";
                        }
                    }
                    num%=100;
                }if(num >= 50){
                    rem = (num/10)*10;
                    if(rem == 90){
                        roman+="XC";
                    }else{
                        roman += "L";
                        rem2 = (rem-50)/10;
                        for(int i=0; i<rem2; i++){
                            roman += "X";
                        }
                    }
                    num%=10;
                }if(num >= 10){
                    rem = (num/10)*10;
                    if(rem == 40){
                        roman+="XL";
                    }else{
                        rem2 = (rem)/10;
                        for(int i=0; i<rem2; i++){
                            roman += "X";
                        }
                    }
                    num%=10;
                }if(num >= 5){
                    rem = num%10;
                    if(rem == 9){
                        roman+="IX";
                    }else{
                        roman += "V";
                        rem2 = rem-5;
                        for(int i=0; i<rem2; i++){
                            roman += "I";
                        }
                    }
                    num=0;
                }if(num >= 1){
                    rem = num%10;
                    if(rem == 4){
                        roman+="IV";
                    }else{
                        for(int i=0; i<rem; i++){
                            roman += "I";
                        }
                    }
                    num=0;
                }
            }
        }
        return roman;
    }
};