bool validPalindrome(char* s) {
    int len = strlen(s);
    int i=0, j=len-1;
    bool isPalindrome(int left, int right){
        while(left<right){
            if(s[left]!=s[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
    
    while (i < j) {
        if (s[i] != s[j]) {
            return isPalindrome(i + 1, j) || isPalindrome(i, j - 1);
        }
        i++;
        j--;
    }
    return true;
}