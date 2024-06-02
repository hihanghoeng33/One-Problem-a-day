void reverseString(char* s, int sSize) {
    char *newS=(char*)malloc(sizeof(char)*(sSize));
    int j=0, left=0, right=sSize-1;
    while(left<right){
        newS = s[left];
        s[left] = s[right];
        s[right] = newS;
        right--;
        left++;
    }
}