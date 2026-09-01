#ifndef LRC_LYRIC_H
#define LRC_LYRIC_H

#include <string>

namespace lrc {
    struct Timestamp {
        int m;
        int s;
        int ms;
    };

    struct Lyric {
        Timestamp ts;
        std::string lyric;
    };
}

#endif