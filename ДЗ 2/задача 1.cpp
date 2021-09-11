#include <iostream>
#include <string>
#include <vector>
int main()
{
    std::vector <std::string> v;
    std::string s, word, symbol;
    std::getline(std::cin, s);
    for (auto i = 0U; i < s.size(); ++i) {
        if (s[i] == ' ') {
            v.push_back(word);
            word = "";
        }
        else if (s[i] == ',' || s[i] == '.' || s[i] == '?') {
            v.push_back(word);
            word = "";
            symbol = s[i];
            v.push_back(symbol);
        }
        else {
            word += s[i];
        }
    }
    v.push_back(word);
    for (auto i = 0U; i < v.size(); ++i) {
        std::cout << v[i] << std::endl;
    }
    system("pause");
    return 0;
}
