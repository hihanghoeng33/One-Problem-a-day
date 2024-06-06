bool isPalindrome(char* s) {
    int len = strlen(s);
    int k=0;
    char *newS=(char*)malloc((len+1)*sizeof(char));
    for(int i=0;i<len;i++){
        if(isalpha(s[i])||(s[i]<='9' && s[i]>='0')){
            newS[k++] = tolower(s[i]);
        }
    }
    int i = k-1, j=0;
    while(i>j){
        if(newS[i]!=newS[j]){
            return false;
        }
        i--;
        j++;
    }
    free(newS);
    return true;
}