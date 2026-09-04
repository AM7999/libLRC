#include "lrc/Diagnostics.hpp"
#include <lrc/Parser.hpp>

#include <algorithm>
#include <cctype>
#include <iostream>

namespace lrc {

    Parser::Parser() = default;

    Result Parser::parse(const std::string& text) const {
        std::size_t ln = 4;
        std::vector<ParseDiag> diag;
        classify(text, ln, diag);
        return Result{};
    }

    Parser::Parsed Parser::classify(const std::string& line, std::size_t lineNumber, std::vector<ParseDiag>& diagnostics) const {
        Parsed result;

        std::string trimmed = trim(line);

        if(trimmed.empty()) {
            result.kind = Parsed::Kind::Blank;
            return result;

        }

        if(trimmed[0] != '[') {
            result.kind = Parsed::Kind::Malformed;
            return result;
        }

        size_t endBracket = trimmed.find(']');
        if(endBracket == std::string::npos) {
            result.kind = Parsed::Kind::Malformed;
            diagnostics.push_back({Severity::Warning, lineNumber, line,
            "missing terminating ] at end of tag block"});
            return result;
        }

        std::string tagType = trimmed.substr(1, endBracket -1);
        std::string tagValue = trimmed.substr(endBracket+1);

        std::cout << tagType << '\n';
        std::cout << tagValue << '\n';

        return Parsed{};
    }

    const std::string Parser::trim(const std::string& s) const  {
        auto isSpace = [](unsigned char c) { return std::isspace(c); };

        auto start = std::find_if_not(s.begin(), s.end(), isSpace);
        auto end = std::find_if_not(s.rbegin(), s.rend(), isSpace).base();

        return (start < end ) ? std::string(start, end) : std::string();
    }
}