class Solution {
public:
    int hammingDistance(int x, int y) {
        string storeX = bitset<32>(x).to_string();
        string storeY = bitset<32>(y).to_string();
        int count=0;
        for (int i = 0; i < storeX.size(); i++)
        {
            if(storeX[i]!=storeY[i]){
                count++;
            }
        }
        return count;
    }
};