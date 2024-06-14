class Solution {
public:
    string multiply(string num1, string num2) {
        int number1 = num1.size();
        int number2 = num2.size();
        vector<int> result(number1+number2, 0);
        int sum, multiply;
        int i, j;
        for(i=number1-1;i>=0;i--){
            for(j=number2-1;j>=0;j--){
                multiply = (num1[i] - '0')*(num2[j] -'0');
                sum = multiply + result[i+j+1];

                result[i+j+1] = sum%10;
                result[i+j] += sum/10;
            }
        }
        string resultstr;
        for (int k:result) {
            if(!(resultstr.empty()&&k==0)){
                resultstr.push_back(k+'0');
            }
        }
        return (resultstr.empty()) ? "0" : resultstr;
        
    }
};