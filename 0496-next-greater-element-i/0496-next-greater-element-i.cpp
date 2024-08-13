class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> store;
        int maxs = INT_MIN;
        int len = nums1.size(), len1 = nums2.size();
        int i=0, j=0, k=0;
        while(i<len){
            maxs=-1;
            for (j = 0; j < len1; j++)
            {   
                if(nums1[i]==nums2[j]){
                    if(j==len1-1){
                        store.push_back(-1);
                        continue;
                    }
                    maxs = nums2[j];
                    for(k=j+1;k<len1;k++){
                        if(maxs<nums2[k]){
                            maxs = nums2[k];
                            store.push_back(maxs);
                            break;
                        }if(k==len1-1){store.push_back(-1);}
                    }
                }
            }
            i++;
        }
        return store;
    }
};