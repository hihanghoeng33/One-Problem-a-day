class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int len = bills.size();
        int i=0;
        int total5 = 0, total10 = 0;
        while (i<len)
        {
            cout << total5 << endl << total10 << endl;
            if(bills[i]==5){
                total5+=bills[i];
            }else if(bills[i]==10){
                if(total5>0){
                    total10+=10;
                    total5-=5;
                }else{
                    return false;
                }
            }else{
                if(total10>0 && total5>0){
                    total10-=10;
                    total5-=5;
                }else if(total5 >=15){
                    total5-=15;
                }else{
                    return false;   
                }
            }
            i++;
        }
        return (total10 >= 0 && total5 >= 0);
    }
};


