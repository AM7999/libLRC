#ifndef LRC_STRUCTS_H
#define LRC_STRUCTS_H

#include <lrc/Lyric.hpp>
#include <string>

namespace lrc {
    struct Metadata {
        std::string ti;
        std::string ar;
        std::string al;
        std::string au;
        std::string lr;
        Timestamp length;
        std::string by;
    };
}

#endif