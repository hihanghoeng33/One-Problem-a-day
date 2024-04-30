#include <string>

std::string pofi(unsigned n) {
    switch (n % 4) {
        case 0:
            return "1";
        case 1:
            return "i";
        case 2:
            return "-1";
        case 3:
            return "-i";
    }
    return "";
}
