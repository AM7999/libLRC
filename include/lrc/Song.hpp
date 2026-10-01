#ifndef LRC_SONG_H
#define LRC_SONG_H

#include <string>

#include <lrc/Lyrics.hpp>
#include <lrc/Structs.h>

namespace lrc {
    class Song {
        public:
            Song() = default;
            Song(const Metadata& meta, const Lyrics& lyrics) {this->meta = meta;this->lyrics_ = lyrics;}

            // getters and setters
            const std::string& title() const { return meta.ti; }
            void setTitle(std::string& t) { this->meta.ti = t; }

            const std::string& artist() const { return meta.ar; }
            void setArtist(std::string& a) { this->meta.ar= a; }

            const std::string& album() const { return meta.al; }
            void setAlbum(std::string& a) { this->meta.al = a; }

            // no more std::optional
            Timestamp length() const { return meta.length; }
            void setLength(Timestamp& t) { this->meta.length = t; }

            Lyrics& lyrics() { return lyrics_; }
            const Lyrics& lyrics() const { return lyrics_; }
        
        private:
            Metadata meta = {};
            Lyrics lyrics_;
    };
}

#endif
