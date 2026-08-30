#ifndef LYRICS_H
#define LYRICS_H

#include <string>
#include <vector>

struct timestamp {
    int m;
    int s;
    int ms;
};

struct Lyric {
    timestamp ts;
    std::string lyric;
};

class Song {
    public:
        Song(std::string file);
        void printLyrics();

        std::string getTitle() const { return title; }
        std::string getArtist() const { return artist; }
        std::string getAlbum() const { return album; }
        std::string getLyricist() const { return lyricist; }
        timestamp getLength() const { return length; }
        std::string getLrcAuthor() const { return lrcAuthor; }

        std::vector<Lyric> getLyrics() const { return Lyrics; }

    private:
        std::string title;
        std::string artist;
        std::string album;
        std::string lyricist;
        
        timestamp length;

        std::string lrcAuthor;

        //TODO: offset

        std::string version;

        std::vector<Lyric> Lyrics;
};

#endif