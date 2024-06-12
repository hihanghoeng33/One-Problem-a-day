int strStr(char* haystack, char* needle) {
    int len1 = strlen(haystack), len2 = strlen(needle);
    int flag = 0;
    int i, j;
    for(i=0;i<len1;i++){
        flag = 1;
        for(j=0;j<len2;j++){
            if(haystack[i+j]!=needle[j]){
                flag = 0;
                break;
            }
        }
        if(flag){
            return i;
        }
    }
    return -1;
}