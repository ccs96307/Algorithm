#include<iostream>
#include<string>
#include<algorithm>


bool isPalindromic(std::string &str) {
    std::string reversedStr = str;
    std::reverse(reversedStr.begin(), reversedStr.end());
    return str == reversedStr;
}


int DFS(std::string &str, std::string &result, int idx) {
    int currLen = 0;

    // Base case
    if (idx >= str.size()) {
        return 0;
    }

    // Select
    result.push_back(str[idx]);
    if (isPalindromic(result)) {
        currLen = result.size();
    }

    int maxLen = std::max(currLen, DFS(str, result, idx+1));

    // Not select
    result.pop_back();

    maxLen = std::max(maxLen, DFS(str, result, idx+1));

    return maxLen;
}



int main() {
    std::string str = "babad";
    std::string result = "";

    int maxLen = DFS(str, result, 0);

    std::cout << maxLen << std::endl;

    return 0;
}