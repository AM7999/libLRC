// #ifndef SONG_H
// #define SONG_H

// #include <string>

// #include <lrc/Lyric.hpp>
// #include <lrc/Lyrics.hpp>

// namespace lrc {
//     class Song {
//         public:
//             Song(std::string file);
//             Song(std::ifstream& file);

//             const std::string& title() const { return title; }
//             const std::string& artist() const { return artist; }
//             const std::string& album() const { return album; }
//             const std::string& lyricist() const { return lyricist; }
//             const std::string& lrcAuthor() const { return lrcAuthor; }
//             const Timestamp& length() const { return length; }

//             void printLyrics();

//         private:
//             std::string title;
//             std::string artist;
//             std::string album;
//             std::string lyricist;
//             std::string lrcAuthor;
//             Timestamp length;
//             Lyrics lyrics;
//     };
// }

// #endif