#ifndef LRC_PARSER_H
#define LRC_PARSER_H

#include <lrc/Diagnostics.hpp>

namespace lrc {
    class Parser {
    public:
        explicit Parser();

        Result parse(const std::string& text) const;
        Result parse(std::istream& stream) const;
        // might change to ifstream
        Result parseFile(std::string& path) const;

        private:
            struct Parsed {
                enum class Kind { Metadata, Lyric, Comment, Blank, Malformed } kind;
                std::string tag;
                std::string value;
                Timestamp ts;
            };

            Parsed classify(const std::string& line, std::size_t lineNumber, std::vector<ParseDiag>& diagnostics) const;

            bool tryTimestamp(const std::string& raw, Timestamp& out) const;
            void applyMetadata(Song& song, const std::string& tag, const std::string& val) const;

            const std::string trim(const std::string& s) const;
    };
}



#endif