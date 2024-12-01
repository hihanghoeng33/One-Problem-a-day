class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        int len = arr.size();
        int flag = 0;
        for(int i=0;i<len;i++){
            flag = (arr[i]%2==0) ? arr[i] : INT_MIN;
            for(int j=0;j<len;j++){
                if(arr[j]==flag/2 && j!=i){
                    cout << "Nilai i adalah " << i << " dan nilai j adalah " << j << endl;
                    return true;
                }
            }
        }
        return false;
    }
};