#ifndef LYRICS_H
#define LYRICS_H

#include <optional>
#include <vector>
#include <lrc/Lyric.hpp>

namespace lrc {
    class Lyrics {
        public:
            // blank constructor
            Lyrics() = default;
            explicit Lyrics(std::vector<Lyric> lines);

            std::size_t size() const { return lines.size(); }
            bool empty() const { return lines.empty(); }
            // return lyric at line index
            const Lyric& at(std::size_t index) const { return lines.at(index); }

            std::vector<Lyric>::const_iterator begin() const { return lines.begin(); }
            std::vector<Lyric>::const_iterator end() const { return lines.end(); }

            // mutation
            void insert(const Lyric& lyric);
            void remove(std::size_t index);

            std::optional<Lyric> lyricAt(Timestamp t);

        private:
            void sort();

            std::vector<Lyric> lines;
    };
}

#endif