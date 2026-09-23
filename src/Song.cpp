#include <lrc/Song.hpp>

namespace lrc {
    Song::Song(const Metadata& meta, const Lyrics& lyrics) {
        this->title_ = meta.ti;
        this->artist_ = meta.ar;
        this->album_ = meta.al;
        this->author_ = meta.au;
        this->lyricist_ = meta.lr;
        this->length_ = meta.length;
        this->lrcAuthor_ = meta.by;

        this->lyrics_ = lyrics;
    }
}
