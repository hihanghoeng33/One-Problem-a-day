int specialArray(int* nums, int numsSize) {
    int check = 1,count=0, maks = -1, x=0, i=0, j=0;
    for(i=0;i<numsSize;i++){
        if(nums[i]>=maks)
            maks = nums[i];
    }
    for(x=0;x<=maks;x++){
        for(j=0;j<numsSize;j++){
            if(nums[j]>=x){
                count++;
            }
        }
        if(count==x){
            return x;
        }else{
            count=0;
        }
    }
    return (count!=0) ? count : -1;
}
