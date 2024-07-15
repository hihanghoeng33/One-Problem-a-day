int minimumChairs(char* s) {
    int len = strlen(s);
    int total = 0, max = -1;
    for(int i=0;i<len;i++){
        
        if(s[i]=='E'){
            total+=1;
        }else{
            total-=1;
        }
        if(max<total) max=total;
    }
    return max;
}