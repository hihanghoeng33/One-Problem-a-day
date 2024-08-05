class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        vector<string> store; vector<int> yes;
        int i=0, j=0, check=0;
        int len = arr.size();
        for(i=0;i<len;i++){
            check = 1;
            for(j=0;j<len;j++){
                if(arr[i]==arr[j] && i!=j){
                    check = 0;
                    break;
                }
            }
            if(check){
                store.push_back(arr[i]);
            }
        }
        if (k <= store.size()) {
            return store[k - 1];
        } else {
            return "";
        } 
    }
};