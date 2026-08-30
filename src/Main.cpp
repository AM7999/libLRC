#include <string>
#include <sstream>
#include <vector>
#include <iostream>

#include <lrc/Lyrics.hpp>

Song::Song(std::string file) {
    std::vector<std::string> lines;
    std::stringstream ss(file);
    std::string line;

    while(std::getline(ss,line,'\n')) {
        lines.push_back(line);
    }

    for(const std::string& l : lines) {
        if(l.empty() || l[0] != '[') {
            continue;
        }

        size_t endBracket = l.rfind("]");

        size_t titleStart = l.find("[ti:");
        if(titleStart != std::string::npos) {
            std::string title = l.substr(titleStart + 4, endBracket - titleStart - 4);
            std::cout << "Title: " << title << std::endl;
            this->title = title;
        }

        if(endBracket != std::string::npos) {
            std::string lyr = l.substr(endBracket + 1);
            if(!lyr.empty()) {
                Lyrics.push_back({0,0,0,lyr});
            }
        }
    }
}

void Song::printLyrics() {
    for(const Lyric& l : Lyrics) {
        std::cout << l.ts.m << ":" << l.ts.s << "." << l.ts.ms << " " << l.lyric << std::endl;
    }
}