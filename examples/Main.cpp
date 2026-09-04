// #include <iostream>
// #include <fstream>

// #include <lrc/Lyrics.hpp>

// int main(int argc, char* argv[]) {
//     if(argc < 2) {
//         std::cout << "Usage: " << argv[0] << " <lyrics_file>" << std::endl;
//         return 1;
//     }

//     std::ifstream file{std::string(argv[1])};
//     if (!file.is_open()) {
//         std::cout << "could not open file" << std::endl;
//         return 1;
//     }

//     std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
//     file.close();

    

//     return 0;
// }

#include <iostream>
#include <string>
#include <algorithm>

void ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
        return !std::isspace(ch);
    }));
}

// Trim from the end (in place)
void rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
    }).base(), s.end());
}

void trim(std::string& s) {
    rtrim(s);
    ltrim(s);
}

int main() {
    std::string thing = "         hello      ";

    trim(thing);

    std::cout << thing << std::endl;
}