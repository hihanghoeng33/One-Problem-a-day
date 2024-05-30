int myAtoi(char* s) {
    int i = 0;
    int sign = 1;
    int result = 0;
    int len = strlen(s);

    while (i < len && isspace(s[i])) {
        i++;
    }

    if (i < len && (s[i] == '-' || s[i] == '+')) {
        if (s[i] == '-') {
            sign = -1;
        }
        i++;
    }

    while (i < len) {
        if(s[i]<='9'&&s[i]>='0'){
            int digit = s[i] - '0';

            if (result > (INT_MAX - digit) / 10) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }
            result = result * 10 + digit;
        }else{
            break;
        }
        i++;
    }

    return sign * result;
}