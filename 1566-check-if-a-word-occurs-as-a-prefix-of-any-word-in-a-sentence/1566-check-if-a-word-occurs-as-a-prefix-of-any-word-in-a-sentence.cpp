class Solution {  
public:  
    int isPrefixOfWord(string sentence, string searchWord) {  
        istringstream stream(sentence); 
        string word;  
        int count = 1; 

         
        while (stream >> word) {  
            if (word.find(searchWord) == 0) { 
                return count;  
            }  
            count++;  
        }  
        
        return -1; 
    }  
};