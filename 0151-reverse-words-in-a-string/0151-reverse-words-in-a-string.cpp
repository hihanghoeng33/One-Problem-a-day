class Solution {
public:
    string reverseWords(string s) {
        string baru = "";
        stack<string> hasil;
        int len = s.length();
        for(int i = 0; i < len; i++){
            if(!isspace(s[i])){
                baru += s[i];
            }else if (s[i] == ' ' && !baru.empty()) {
                hasil.push(baru);
                baru = "";
            }
        }
        if (!baru.empty()) {
            hasil.push(baru);
        }

        string simpan = "";
        while (!hasil.empty()) {
            simpan += hasil.top();
            hasil.pop();
            if (!hasil.empty()) {
                simpan += " ";
            }
        }
        
        return simpan;
    }
};
