#include <lrc/Diagnostics.hpp>
#include <lrc/Song.hpp>
#include <lrc/Lyric.hpp>
#include <lrc/Parser.hpp>
#include <lrc/Lyrics.hpp>

#include <iostream>
#include <fstream>

int main() {
    std::ifstream file("../ioit.lrc");
    if (!file) {
        std::cerr << "Error when reading file\n";
    }

    lrc::Parser parser;
    lrc::Result s = parser.parseFile(file);
    lrc::Song song = s.song;

    //std::cout << lyrics.at(0);

    return 0;
}