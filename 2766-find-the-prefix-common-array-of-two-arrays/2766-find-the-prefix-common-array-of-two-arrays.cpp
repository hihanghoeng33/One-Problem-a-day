class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
       vector<int> res;
       int len = A.size();
       int m = 0;
       int count = 0;
       while(m<len){
        count = 0;
        for(int i=0;i<=m;i++){
            for(int j=0;j<=m;j++){
                if(A[i]==B[j]){
                    cout << "elemen yang sama " << A[i] << " di m = " << m << endl;
                    count++;
                }
            }
        }
        res.push_back(count);
        m++;
       }
        return res;
    }
};