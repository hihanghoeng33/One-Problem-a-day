class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
            return false;
        string newS = to_string(x);
        int len = newS.length();
        int i=0, j=len-1;
        while(i<j){
            if(newS[j]!=newS[i]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};