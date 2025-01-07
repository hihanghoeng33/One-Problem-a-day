class Solution {
public:
    vector<int> minOperations(string boxes) {
        int count = 0;
        vector<int> store;
        int len = boxes.length();
        cout << len;
        for(int i=0;i<len;i++){
            count = 0;
            for(int j=0;j<len;j++){
                if(boxes[j]=='1'){
                    count+=abs(i-j);
                }
            }
            store.push_back(count);
        }
        return store;
    }
};