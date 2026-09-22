#include <lrc/Diagnostics.hpp>
#include <lrc/Song.hpp>
#include <lrc/Lyric.hpp>
#include <lrc/Parser.hpp>
#include <lrc/Lyrics.hpp>

#include <iostream>
#include <fstream>

int main(int argc, char* argv[]) {
    if(argc == 1) {
        std::cout << argv[0] << " <file>\n";
        return 1;
    }
    
    std::ifstream file(argv[1]);
    if (!file) {
        std::cerr << "Error when reading file\n";
    }

    lrc::Parser parser;
    lrc::Result s = parser.parseFile(file);

    std::cout << "break\n";

    return 0;
}
