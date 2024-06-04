int singleNumber(int* nums, int numsSize) {
    long freq[60002]={0}, i=0;
    for(i=0;i<numsSize;i++){
        nums[i]+=30001;
        freq[nums[i]]++;
    }
    for(i=0;i<60002;i++){
        if(freq[i]==1){
            return i-30001;
        }
    }
    return 0;
}