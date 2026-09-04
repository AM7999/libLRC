#ifndef LRC_SONG_H
#define LRC_SONG_H

#include <string>
#include <optional>

#include <lrc/Lyrics.hpp>
#include <lrc/Lyric.hpp>

namespace lrc {
    class Song {
        public:
            Song() = default;
            Song(Lyrics lyrics);

            // getters and setters
            const std::string& title() const { return title_; }
            void setTitle(std::string& t) { this->title_ = t; }

            const std::string& artist() const { return artist_; }
            void setArtist(std::string& a) { this->artist_ = a; }

            const std::string& album() const { return album_; }
            void setAlbum(std::string& a) { this->album_ = a; }

            std::optional<Timestamp> length() const { return length_; }
            void setLength(Timestamp& t) { length_ = t; }

            Lyrics& lyrics() { return lyrics_; }
            const Lyrics& lyrics() const { return lyrics_; }
        
        private:
            std::string title_;
            std::string artist_;
            std::string album_;
            std::string lyricist_;
            std::string lrcAuthor_;
            std::optional<Timestamp> length_;
            Lyrics lyrics_;
    };
}

#endif