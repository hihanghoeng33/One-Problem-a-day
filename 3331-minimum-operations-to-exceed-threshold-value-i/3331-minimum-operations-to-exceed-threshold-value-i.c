int minOperations(int* nums, int numsSize, int k) {
    int count = 0;
    for(int i=0;i<numsSize;i++){
        if(k>nums[i]){
            count++;
        }
    }
    return count;
}