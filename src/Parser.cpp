#include <lrc/Parser.hpp>
#include <lrc/Structs.h>
#include <lrc/Lyric.hpp>

#include <algorithm>
#include <cctype>
#include <iostream>
#include <fstream>

namespace lrc {

    Parser::Parser() = default;

    Result Parser::parse(const std::string& text) const {
        std::size_t ln = 4;
        std::vector<ParseDiag> diag;
        classify(text, ln, diag);
        return Result{};
    }

    Result Parser::parseFile(std::ifstream& file) const {
        std::size_t ln = 4;
        std::vector<ParseDiag> diag = {};
        std::vector<std::string> text = loadFileAsString(file);

        Metadata meta = {};

        std::vector<Lyric> lr;

        for(std::string& line : text) {
            Parser::Parsed parsedLine = classify(line, ln, diag);

            switch(parsedLine.kind) {
                case Parsed::Kind::Lyric:
                    std::cout << "added new Parsed::Kind::Lyric of: " << parsedLine.value << std::endl;
                    lr.push_back({parsedLine.ts, parsedLine.value});
                    break;
                case Parsed::Kind::Metadata:
                    std::cout << "added new Parsed::Kind::Metadata of: " << std::endl;
                    break;
                default:
                    std::cout << " " << std::endl;
            }
        }

        return Result {
            Song(meta, Lyrics(lr)),
            diag
        };
    }

    std::vector<std::string> Parser::loadFileAsString(std::ifstream& stream) const {
        std::string line;
        std::vector<std::string> lines;
        while(std::getline(stream, line)) {
            lines.push_back(line);
        }
        return lines;
    }

    bool Parser::tryTimestamp(const std::string& raw, Timestamp& out) const {
        size_t colonPos = raw.find(':');
        size_t dotPos = raw.find('.');
        if(colonPos == std::string::npos || dotPos == std::string::npos || dotPos < colonPos) {
            return false;
        }

        try {
            int m = std::stoi(raw.substr(0,colonPos));
            int s = std::stoi(raw.substr(colonPos + 1, dotPos - colonPos -1));
            std::string fracStr = raw.substr(dotPos + 1);
            
            int frac = std::stoi(fracStr);
            int ms = (fracStr.size() == 2) ? frac * 10 : frac;

            out.ms = (static_cast<int64_t>(m)*60+s)*1000+ms;
            return true;
        }
        catch(std::exception&) {
            return false;
        }
    }

    Parser::Parsed Parser::classify(const std::string& line, std::size_t lineNumber, std::vector<ParseDiag>& diagnostics) const {
        Parsed result = {};

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

        size_t colonPos = tagType.find(':');
        Timestamp ts;
        bool isTimestamp = (colonPos!=std::string::npos) && tryTimestamp(tagType, ts);

        if(isTimestamp) {
            result.kind = Parsed::Kind::Lyric;
            result.ts = ts;
            result.value = tagValue;
            return result;
        }

        if(colonPos != std::string::npos) {
            result.kind = Parsed::Kind::Metadata;
            result.tag = tagType.substr(0, colonPos);
            result.value = trim(tagType.substr(colonPos+1));
            return result;
        }

        result.kind = Parsed::Kind::Malformed;
        diagnostics.push_back({Severity::Warning, lineNumber, line, "Bracket content is not tag or timesamp"});
        return result;
    }

    const std::string Parser::trim(const std::string& s) const  {
        auto isSpace = [](unsigned char c) { return std::isspace(c); };

        auto start = std::find_if_not(s.begin(), s.end(), isSpace);
        auto end = std::find_if_not(s.rbegin(), s.rend(), isSpace).base();

        return (start < end ) ? std::string(start, end) : std::string();
    }
}
