class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int len1 = ransomNote.size(), len2 = magazine.size();
        
        if (len1 > len2) {
            return false;
        }
        
        sort(ransomNote.begin(), ransomNote.end());
        sort(magazine.begin(), magazine.end());

        int i = 0, j = 0;
        
        while (i < len1 && j < len2) {
            if (ransomNote[i] == magazine[j]) {
                i++;
                j++;
            } else if (ransomNote[i] > magazine[j]) {
                j++;
            } else {
                return false;
            }
        }

        return i == len1;
    }
};
