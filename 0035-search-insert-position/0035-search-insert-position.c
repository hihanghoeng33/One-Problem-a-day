int searchInsert(int* nums, int numsSize, int target) {
    int count = 0;
    for(int i=0;i<numsSize;i++){
        if(nums[i]==target){
            return i;
        }else if(nums[i]<target){
            count++;
        }else if(nums[i]>target){
            return i;
        }
    }
    return count;
}