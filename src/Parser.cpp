#include <lrc/Parser.hpp>

namespace lrc {
    Parser::Parsed Parser::classify(const std::string& line, std::size_t lineNumber, std::vector<ParseDiag>& diagnostics) const {
        Parsed result;

        std::string trimmed = trim(line);
    }

    const std::string Parser::trim(const std::string& s) const  {
        auto isSpace = [](unsigned char c) { return std::isspace(c); };

        auto start = std::find_if_not(s.begin(), s.end(), isSpace);
        auto end = std::find_if_not(s.rbegin(), s.rend(), isSpace).base();

        return (start < end ) ? std::string(start, end) : std::string();
    }
}