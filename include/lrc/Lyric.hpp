#ifndef LRC_LYRIC_H
#define LRC_LYRIC_H

#include <cstdint>
#include <ostream>
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

        friend std::ostream& operator <<(std::ostream& outs, const Lyric& l) {
            return outs << l.ts.ms << ", " << l.lyric;
        }
    };
}

#endif