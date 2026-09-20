#ifndef LRC_STRUCTS_H
#define LRC_STRUCTS_H

#include <lrc/Lyric.hpp>
#include <string>

namespace lrc {
    struct Metadata {
        std::string t;
        std::string a;
        std::string al;
        std::string ly;
        std::string lat;
        Timestamp l;
    };
}

#endif