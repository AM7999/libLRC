#ifndef LRC_PARSERESULT_H
#define LRC_PARSERESULT_H

#include <string>
#include <vector>

#include <lrc/Song.hpp>

namespace lrc {
    // just something to have
    enum class Severity { Warning, Error };

    // if something went wrong fill out this struct
    struct ParseDiag {
        Severity sv;
        std::size_t lineNumber;
        std::string line;
        std::string message;
    };

    struct Result {
        // provide a Song
        Song song;
        // and if anything happened like a warning or error
        // a diagnostic is added here
        std::vector<ParseDiag> diagnostics;

        bool hasErrors() const;
        // if hasErrors is true ok is false
        // inverse is true
        bool ok() const { return !hasErrors(); }
    };
}

#endif