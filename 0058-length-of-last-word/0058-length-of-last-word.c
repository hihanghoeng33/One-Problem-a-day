int lengthOfLastWord(char* s) {
    char *newS[strlen(s)+1], check = 0;
    int len = strlen(s), lenlastW = 0;
    int i=len-1, j=0;
    for(i=len-1;i>=0;i--){
        if(isspace(s[i]) && check == 0){
            check = 0;
        }else if(isspace(s[i]) && check == 1){
            break;
        }else if(check == 1 || !isspace(s[i])){
            check = 1;
            lenlastW++;
        }
    }
    return lenlastW;
}