#include <lrc/Diagnostics.hpp>
#include <lrc/Song.hpp>
#include <lrc/Lyric.hpp>
#include <lrc/Parser.hpp>
#include <lrc/Lyrics.hpp>

int main() {
    std::string line = "[00:16.109]That they didn't really matter until you";

    lrc::Parser parser;
    lrc::Result s = parser.parse(line);
    

    return 0;
}