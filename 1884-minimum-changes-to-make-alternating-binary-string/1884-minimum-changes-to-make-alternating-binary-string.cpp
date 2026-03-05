class Solution {
public:
    int minOperations(string s) {
        int count1 = 0, count2 = 0;
        int len = s.length();
        for (int i = 0; i < len; i++){
            char flag1 = (i%2 == 0 ? '1' : '0');
            char flag2 = (i%2 == 0 ? '0' : '1');

            if(s[i] != flag1) count1++;
            if(s[i] != flag2) count2++;
            cout << "count1: " << count1 << " count 2: " << count2 << endl;
        }
        return count1 < count2 ? count1 : count2;
    }
};