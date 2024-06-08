class Solution {
public:
    bool isValid(string s) {
        stack<char>str;
        int check=0;
        for(char &c:s){
            if(c =='{' || c =='(' || c == '['){
                str.push(c);
                check++;
            }else{
                if(check){
                    if(c == ']'){
                        if(str.top()=='['){
                            str.pop();
                        }
                    }else if(c == ')'){
                        if(str.top()=='('){
                            str.pop();
                        }
                    }else if(c == '}'){
                        if(str.top()=='{'){
                            str.pop();
                        }
                    }
                    check--;
                }else{
                    return false;
                }
            }
        }
        return (str.empty());
    }
};