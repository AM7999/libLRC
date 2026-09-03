#include <iostream>
#include <fstream>

#include <lrc/Lyrics.hpp>

int main(int argc, char* argv[]) {
    if(argc < 2) {
        std::cout << "Usage: " << argv[0] << " <lyrics_file>" << std::endl;
        return 1;
    }

    std::ifstream file{std::string(argv[1])};
    if (!file.is_open()) {
        std::cout << "could not open file" << std::endl;
        return 1;
    }

    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    file.close();

    

    return 0;
}