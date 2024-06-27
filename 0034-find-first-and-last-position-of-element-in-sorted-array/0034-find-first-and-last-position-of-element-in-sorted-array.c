/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int* result = (int*)malloc(sizeof(int)*2);
    result[0] = -1;
    result[1] = -1;
    *returnSize = 2;

    for(int i=0;i<numsSize;i++){
        if(nums[i]==target){
            if(result[0]==-1){result[0]=i;}
            result[1]=i;
        }
    }
    return result;
}