#include <lrc/Lyrics.hpp>

namespace lrc {
    Lyrics::Lyrics(std::vector<Lyric> lines) {

    }

    void Lyrics::insert(const Lyric& lyric) {

    }

    void Lyrics::remove(std::size_t index) {
        delete(lines[index]);
    }

    std::optional<Lyric> Lyrics::lyricAt(Timestamp t) {
        for(Lyric& l : lines) {
            if(l.ts == t) {
                return l;
            }
        }
        return {};
    }
}