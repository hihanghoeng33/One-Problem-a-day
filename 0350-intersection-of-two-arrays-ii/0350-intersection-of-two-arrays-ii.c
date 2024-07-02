/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int* res = (int*)malloc(sizeof(int) * (nums1Size < nums2Size ? nums1Size : nums2Size)); 
    int* used = (int*)calloc(nums2Size, sizeof(int)); // Array to mark used elements in nums2
    int k = 0;

    for (int i = 0; i < nums1Size; i++) {
        for (int j = 0; j < nums2Size; j++) {
            if (nums1[i] == nums2[j] && !used[j]) {
                res[k++] = nums1[i];
                used[j] = 1; // Mark this element as used
                break;
            }
        }
    }

    free(used); // Free the used array
    res = (int*)realloc(res, sizeof(int) * k); // Resize the result array to the actual number of intersections
    *returnSize = k;
    return res;
}