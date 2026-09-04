#include <lrc/Lyrics.hpp>

namespace lrc {
    Lyrics::Lyrics(std::vector<Lyric> lines) {

    }

    void Lyrics::insert(const Lyric& lyric) {
        // add and resort lyrics
        lines.push_back(lyric);
        sort();
    }

    void Lyrics::remove(std::size_t index) {
        lines.erase(lines.begin() + index);
        sort();
    }

    std::optional<Lyric> Lyrics::lyricAt(Timestamp t) {
        for(Lyric& l : lines) {
            if(l.ts == t) {
                return l;
            }
        }
        return {};
    }

    void Lyrics::sort() {
        // simple insertion sort
        for (std::size_t i = 1; i < lines.size(); ++i) {
            Lyric key = lines[i];
            std::size_t j = i;

            while (j > 0 && lines[j - 1].ts > key.ts) {
                lines[j] = lines[j - 1];
                --j;
            }

            lines[j] = key;
        }
    }
}