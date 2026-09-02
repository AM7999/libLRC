#ifndef LYRICS_H
#define LYRICS_H

#include <ostream>
#include <string>

#include <lrc/Lyric.hpp>

namespace lrc {

    class Lyrics {
        public: 
    }

    class Song {
        public:
            // constructors
            // from string
            Song(std::string file);
            // from ifstream (file)
            Song(std::ifstream& file);

            void printLyrics();

            // getters
            std::string getTitle() const { return title; }
            std::string getArtist() const { return artist; }
            std::string getAlbum() const { return album; }
            std::string getLyricist() const { return lyricist; }
            Timestamp getLength() const { return length; }
            std::string getLrcAuthor() const { return lrcAuthor; }

            // setters
            void setTitle(const std::string& t) { title = t; }
            void setArtist(const std::string& a) { artist = a; }
            void setAlbum(const std::string& a) { album = a; }
            void setLyricist(const std::string& l) { lyricist = l; }
            void setLength(const Timestamp& t) { length = t; }
            void setLrcAuthor(const std::string& a) { lrcAuthor = a; }

            friend std::ostream& operator<<(std::ostream& os, const Song& song);

        private:
            Timestamp length;
            std::string title;
            std::string artist;
            std::string album;
            std::string lyricist;
            std::string lrcAuthor;
            //TODO: offset
            std::string version;
    };
}



#endif