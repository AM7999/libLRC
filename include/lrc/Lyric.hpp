#ifndef LRC_LYRIC_H
#define LRC_LYRIC_H

#include <string>

namespace lrc {
    struct Timestamp {
        int64_t ms;

        // allows comparisons using < and == 
        bool operator >(const Timestamp& other) const { return ms > other.ms; }
        bool operator <(const Timestamp& other) const { return ms < other.ms; }
        bool operator ==(const Timestamp& other) const { return ms == other.ms; }
    };

    struct Lyric {
        Timestamp ts;
        std::string lyric;
    };
}

#endif