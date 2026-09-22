#include <lrc/Song.hpp>

namespace lrc {
    Song::Song(const Metadata& meta, const Lyrics& lyrics) {
        this->title_ = meta.t;
        this->artist_ = meta.a;
        this->album_ = meta.al;
        this->lyricist_ = meta.ly;
        this->lrcAuthor_ = meta.lat;
        this->length_ = meta.l;

        this->lyrics_ = lyrics;
    }
}
