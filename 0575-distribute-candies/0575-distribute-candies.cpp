class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        sort(candyType.begin(), candyType.end());
        vector<int> set;
        int len = candyType.size();
        int i=0;
        for(i=0;i<len;i++){
            if(i==0){set.push_back(candyType[i]);}
            else if(set.back()!=candyType[i]){
                set.push_back(candyType[i]);
            }
        }
        if(len/2<=set.size()){return len/2;}
        return set.size();
    }
};