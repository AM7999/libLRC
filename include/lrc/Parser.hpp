#ifndef LRC_PARSER_H
#define LRC_PARSER_H

#include <string>
#include <lrc/Lyric.hpp>
#include <lrc/Diagnostics.hpp>
#include <lrc/Song.hpp>

namespace lrc {

    class Parser {
        public:
            explicit Parser();

            Result parse(const std::string& text) const;
            Result parse(std::istream& stream) const;
            // changed to ifstream :3
            Result parseFile(std::ifstream& path) const;

        private:
            struct Parsed {
                enum class Kind { Metadata, Lyric, Comment, Blank, Malformed } kind;
                std::string tag;
                std::string value;
                Timestamp ts;
            };

            std::vector<std::string> loadFileAsString(std::ifstream& stream) const;

            Parsed classify(const std::string& line, std::size_t lineNumber, std::vector<ParseDiag>& diagnostics) const;
            
            bool tryTimestamp(const std::string& raw, Timestamp& out) const;
            void applyMetadata(Song& song, const std::string& tag, const std::string& val) const;

            const std::string trim(const std::string& s) const;
    };
}



#endif
