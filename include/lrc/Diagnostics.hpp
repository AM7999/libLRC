#ifndef LRC_PARSERESULT_H
#define LRC_PARSERESULT_H

#include <string>
#include <vector>
#include <lrc/Song.hpp>

namespace lrc {
    // 
    enum class Severity { Warning, Error };

    // if something went wrong fill out this struct
    struct ParseDiag {
        // Warning or Error
        Severity sv;
        // what line number the issue occurs on
        std::size_t lineNumber;
        std::string line;
        // what whent wrong
        std::string message;
    };

    struct Result {
        // provide a Song
        Song song;
        // and if anything happened like a warning or error
        // a diagnostic is added here
        std::vector<ParseDiag> diagnostics;
        // return no if diagnostics is empty
        // return yes if theres something in there
        bool ok() const { return !diagnostics.empty(); }
    };
}

#endif
