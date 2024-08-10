class Solution {
public:
    string reverseWords(string s) {
        s += " ";
        int count = s.size();
        string hasil = "";
        string baru = "";
        for (int i = 0; i <= count; i++)
        {
            if(!isspace(s[i])){
                baru+=s[i];
            }else if(isspace(s[i])){
                reverse(baru.begin(), baru.end());
                hasil += baru;
                if(i!=count-1) hasil += " ";
                baru.clear();
            }
            //cout << hasil << endl;
        }
        return hasil;
    }
};