#include<iostream>
#include<string>
#include<algorithm>


int expand(std::string &str, int left, int right) {
    int currMaxLen = 0;
    while (left >= 0 && right < str.size() && str[left] == str[right]) {
        currMaxLen = right - left + 1;
        --left;
        ++right;
    }
    
    return currMaxLen;
}


int longest_palindromic_substring(std::string &str) {
    int maxLen = 0;

    for (int i=0; i<str.size(); ++i) {
        maxLen = std::max(maxLen, expand(str, i, i));
        maxLen = std::max(maxLen, expand(str, i, i + 1));
    }

    return maxLen;
}



int main() {
    std::string str = "babad";

    int maxLen = longest_palindromic_substring(str);

    std::cout << maxLen << std::endl;

    return 0;
}