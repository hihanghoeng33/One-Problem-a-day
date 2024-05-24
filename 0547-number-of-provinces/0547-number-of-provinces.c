void dfs(int **isConnected, int isConnectedSize, int *check, int i){
    for(int j=0;j<isConnectedSize;j++){
        if(isConnected[i][j]==1&&!check[j]){
            check[j] = 1;
            dfs(isConnected, isConnectedSize, check, j);
        }
    }
}
int findCircleNum(int** isConnected, int isConnectedSize, int* isConnectedColSize) {
    int i=0, j=0, count=0;
    int *check=calloc(isConnectedSize, sizeof(int));
    for(i=0;i<isConnectedSize;i++){
        if(!check[i]){
            dfs(isConnected, isConnectedSize, check, i);
            count++;
        }
    }

    return count;
}