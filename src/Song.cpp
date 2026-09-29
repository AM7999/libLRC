#include <lrc/Song.hpp>

namespace lrc {
    // if anything i could probably just move this constructor to the header :/
    Song::Song(const Metadata& meta, const Lyrics& lyrics) {
        this->meta = meta;
        this->lyrics_ = lyrics;
    }
}
