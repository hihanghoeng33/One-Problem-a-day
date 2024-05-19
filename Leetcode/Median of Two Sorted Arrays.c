double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int combine = nums1Size+nums2Size;
    int* combine_arr = (int*)malloc(combine*sizeof(int));
    for(int i=0;i<nums1Size;i++){
        combine_arr[i] = nums1[i];
    }
    for(int i=0;i<nums2Size;i++){
        combine_arr[nums1Size+i] = nums2[i];
    }
    int temp;
    for(int i=0;i<combine-1;i++){
        for(int j=0;j<combine-i-1;j++){
            if(combine_arr[j] > combine_arr[j+1]){
                temp = combine_arr[j];
                combine_arr[j] = combine_arr[j+1];
                combine_arr[j+1] = temp;
            }
        }
    }
    double med;
    if((combine+1)%2==0){
        med = combine_arr[combine/2];
    }else{
        med=(double)(combine_arr[combine/2-1]+combine_arr[combine/2])/2;
    }
    
    return med;
}
