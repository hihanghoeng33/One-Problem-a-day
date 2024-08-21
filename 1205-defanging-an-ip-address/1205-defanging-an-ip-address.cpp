class Solution {
public:
    string defangIPaddr(string address) {
        string baru;
        for(char c:address){
            (c=='.') ? baru+="[.]" : baru+=c;
        }
        return baru;
    }
};