#include <string>
#include <sstream>
#include <vector>
#include <iostream>

#include <lrc/Lyrics.hpp>

// too lazy to just want to namespace lrc {} the stuff rn soooooo
using namespace lrc;

Song::Song(std::string file) {
    std::vector<std::string> lines;
    std::stringstream ss(file);
    std::string line;

    while(std::getline(ss,line,'\n')) {
        lines.push_back(line);
        // 1
        // i was fine, with the men
    }

    for(const std::string& l : lines) {
        // if comment, empty or invalid skip line
        if(l.empty() || l[0] != '[' || l[0] == '#') {
            continue;
        }

        // see if a line actually has a closing bracket and if not just skip
        size_t endBracket = l.rfind("]");
        if(endBracket == std::string::npos) {
            std::cerr << "(libLRC, Main.cpp 23:9) Missing closing bracket on line: \"" << l << "\" continuing..." << std::endl;
            continue;
        }

        // parse lrc metadata
        //title
        size_t titleStart = l.find("[ti:");
        if(titleStart != std::string::npos) {
            std::string title = l.substr(titleStart + 4, endBracket - titleStart - 4);
            this->title = title;
        } else if(titleStart == std::string::npos) {
            this->title = "Unknown";
        }

        //artist
        size_t artistStart = l.find("[ar:");
        if(artistStart != std::string::npos) {
            std::string artist = l.substr(artistStart + 4, endBracket - artistStart - 4);
            this->artist = artist;
        } else if(artistStart == std::string::npos) {
            this->artist = "Unknown";
        }

        //album
        size_t albumStart = l.find("[al:");
        if(albumStart != std::string::npos) {
            std::string album = l.substr(albumStart + 4, endBracket - albumStart - 4);
            this->album = album;
        } else if(albumStart == std::string::npos) {
            this->album = "Unknown";
        }

        //author
        size_t authorStart = l.find("[au:");
        if(authorStart != std::string::npos) {
            std::string author = l.substr(authorStart + 4, endBracket - authorStart - 4);
            this->lrcAuthor = author;
        } else if(authorStart == std::string::npos) {
            this->lrcAuthor = "Unknown";
        }

        //lyricist
        size_t lyricistStart = l.find("[lr:");
        if(lyricistStart != std::string::npos) {
            std::string lyricist = l.substr(lyricistStart + 4, endBracket - lyricistStart - 4);
            this->lyricist = lyricist;
        } else if(lyricistStart == std::string::npos) {
            this->lyricist = "Unknown";
        }

        //length of the song
        size_t lengthStart = l.find("[length:");
        if(lengthStart != std::string::npos) {
            std::string lengthStr = l.substr(lengthStart + 8, endBracket - lengthStart - 8);
            int m = 0, s = 0;
            size_t colonPos = lengthStr.rfind(":");

            if(colonPos != std::string::npos) {
                // https://en.wikipedia.org/wiki/LRC_(file_format) denotes that the length tag only holds m and s
                m = std::stoi(l.substr(lengthStart+8, colonPos));
                // after length, after the colon seperating m and limit to the last bracket
                s = std::stoi(l.substr(lengthStart + 8 + colonPos + 1, endBracket - lengthStart - 8 - colonPos - 1));
                // write back to length
                this->length = {m, s, 0};
                // hardcoded ms. read above
            }
        }

        if(endBracket != std::string::npos) {
            std::string lyr = l.substr(endBracket + 1);
            int m = 0, s = 0, ms = 0;
            if(!lyr.empty()) {
                std::string ts = l.substr(1, endBracket - 1);
                size_t colonPos = ts.find(":");
                size_t dotPos = ts.find(".");
                if(colonPos != std::string::npos && dotPos != std::string::npos) {
                    m = std::stoi(ts.substr(0, colonPos));
                    s = std::stoi(ts.substr(colonPos + 1, dotPos - colonPos - 1));
                    ms = std::stoi(ts.substr(dotPos + 1));
                }
                // TODO: after refactor fix this
                //Lyrics.push_back({m, s, ms, lyr});
            }
        }
    }
}

void Song::printLyrics() {
    // TODO: reimplement this
    // for(const Lyric& l : Lyrics) {
    //     std::cout << l.ts.m << ":" << l.ts.s << "." << l.ts.ms << " " << l.lyric << std::endl;
    // }
}

