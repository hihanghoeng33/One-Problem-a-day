bool threeConsecutiveOdds(int* arr, int arrSize) {
    int count=0;
    for(int i=0;i<arrSize;i++){
        if(arr[i]%2!=0){
            count++;
        }else if(count>=3){
            break;
        }else{
            count=0;
        }
        
    }
    return count>=3;
}