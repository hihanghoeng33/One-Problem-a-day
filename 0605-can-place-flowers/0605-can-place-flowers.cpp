class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int i=0, j=0;
        int len = flowerbed.size();
        while (i<len)
        {
            if (flowerbed[i] == 0 && (i==0 || flowerbed[i-1]==0) && (i==len-1 || flowerbed[i+1]==0))
            {
                n--;
                i += 2;
            }
            else
            {
                i++;
            }
            if (n<=0) return true;
        }
        return false;
    }
};