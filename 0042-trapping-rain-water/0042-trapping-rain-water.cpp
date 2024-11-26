class Solution {
public:
    int trap(vector<int>& height) {
       int l = 0;
       int r = height.size()-1;
       int max_l = 0, max_r = 0, water = 0;
       while(l<r){
        if(height[l]<height[r]){
            if(height[l] > max_l){
                max_l = height[l];
            }else{
                water += max_l-height[l];
            }
            l++;
        }else{
            if(height[r] > max_r){
                max_r = height[r];
            }else{
                water += max_r - height[r];
            }
            r--;
        }
       }
       return water;
    }
};