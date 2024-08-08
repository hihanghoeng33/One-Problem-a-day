class Solution {
public:
    bool checkRecord(string s) {
        int countA = 0, countL = 0;

        for (char c : s) {
            if (c == 'A') {
                countA++;
                if (countA >= 2) return false;
                countL = 0; 
            } else if (c == 'L') {
                countL++;
                if (countL >= 3) return false;
            } else {
                countL = 0;
            }
        }

        return true;
    }
};
