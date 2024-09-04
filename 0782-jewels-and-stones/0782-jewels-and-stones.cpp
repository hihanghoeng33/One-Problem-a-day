class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        // sort(jewels.begin(), jewels.end(), greater<int>());
        // sort(stones.begin(), stones.end(), greater<int>());
        int count = 0;
        for(char c:jewels){
            for(char k:stones){
                if(c==k){
                    count++;
                }
            }
            cout << c << endl;
        }
        return count;
    }
};