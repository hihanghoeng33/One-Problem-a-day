#include <stdbool.h>
bool is_pangram(const char *str_in) {
    bool letters[26] = {false}; 

    for(int i = 0; str_in[i] != '\0'; i++){
        char c = str_in[i];
        if(c >= 'a' && c <= 'z') 
            c -= 32;
        if(c >= 'A' && c <= 'Z') 
            letters[c - 'A'] = true;
    }

    bool isPangram = true;
    for(int i = 0; i < 26; i++){
        if(!letters[i]){ 
            isPangram = false;
            break;
        }
    }
    
    return isPangram;
}
