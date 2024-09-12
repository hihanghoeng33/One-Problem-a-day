class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int counter=0;
        for(int i=0;i<words.size();i++){
            if(compareWords(words[i], allowed)){
                counter++;
            }
        }
        return counter;
    }
private:
    bool compareWords(string m, string n){
        int count=0;
        for(char c:m){
            for(char k:n){
                if(c==k){
                    count++;
                    break;
                }
            }
        }
        return count==m.size();
    }
};