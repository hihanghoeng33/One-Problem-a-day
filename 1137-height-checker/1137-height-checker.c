int heightChecker(int* heights, int heightsSize) {
    int *expected = (int*)malloc(heightsSize * sizeof(int));
    for(int i=0;i<heightsSize;i++){
        expected[i] = heights[i];
    }
    int i=1, j=i-1;
    for (int i = 1; i < heightsSize; i++) {      
        int temp = expected[i];
        j=i-1;
        while (j >= 0 && expected[j] > temp) {
            expected[j + 1] = expected[j];
            j--;
        }
        expected[j + 1] = temp;
    }
    int count = 0;
    for(i=0;i<heightsSize;i++){
        if(expected[i]!=heights[i]){
            count++;
        }
    }
    return count;
}