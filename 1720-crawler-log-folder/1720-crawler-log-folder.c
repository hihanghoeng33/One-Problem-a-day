int minOperations(char** logs, int logsSize) {
    int i = 0;
    int path = 0;
    while(i<logsSize){
        printf("Path: %s\n", logs[i]);
        if(strcmp(logs[i], "../")==0){
            path = (path>0) ? path-1 : 0;
        }else if(strcmp(logs[i], "./")!=0){
            path+=1;
        }
        i+=1;
        printf("Min num: %d\n", path);
    }
    return path;
}