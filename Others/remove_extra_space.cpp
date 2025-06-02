#include <iostream>
#include <string>

void trim(std::string &str) {
    auto strBegin = str.find_first_not_of(" \t\r\n");
    if (strBegin == std::string::npos) {
        return;
    }

    auto strEnd = str.find_last_not_of(" \t\r\n");
    const auto strRange = strEnd - strBegin + 1;

    str = str.substr(strBegin, strRange);
}


void ignoreWhiteSpace(std::string &str) {
    int fillPos = 0;
    bool canSpace = true;

    for (int i=0; i<str.size(); ++i) {
        if (canSpace) {
            str[fillPos] = str[i];
            ++fillPos;
            
            if (str[i] == ' ') {
                canSpace = false;
            }
        }
        else if (str[i] != ' ') {
            str[fillPos] = str[i];
            ++fillPos;
            canSpace = true;
        }
    }

    str = str.substr(0, fillPos);
}


int main() {
    std::string str = "    the    sky   is  blue    ";
    trim(str);
    ignoreWhiteSpace(str);

    std::cout << str << std::endl;

    return 0;
}