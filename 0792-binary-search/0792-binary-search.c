int search(int* nums, int numsSize, int target) {
    int i = 0, j=numsSize-1;
    int left = nums[i], right = nums[j];
    if(numsSize==1){
        if(target!=left){return -1;}
        else{return i;}
    }
    while(i<=j){
        printf("%d %d\n", i, j);
        if(left==target){
            return i;
        }else if(right==target){
            return j;
        }
        i++;
        j--;
        left = nums[i]; right = nums[j];
    }
    return -1;
}