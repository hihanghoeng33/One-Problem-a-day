#include <stdbool.h>
#include <string.h>

bool is_valid_ISBN_10(const char *ISBN) {
    int length = strlen(ISBN);
    if (length != 10) {
        return false;
    }
    
    int sum = 0;
    for (int i = 0; i < 10; ++i) {
        if (ISBN[i] >= '0' && ISBN[i] <= '9') {
            sum += (ISBN[i] - '0') * (i + 1);
        } else if (ISBN[i] == 'X' && i == 9) {
            sum += 10 * (i + 1);
        } else {
            return false;
        }
    }
    
    return (sum % 11 == 0) ? true : false;
}
