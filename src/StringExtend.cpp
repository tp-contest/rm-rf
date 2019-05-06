//
// Created by alex on 06.05.2019.
//

#include "../includes/StringExtend.h"
#include <limits>
#include <stdarg.h>
#include <stdlib.h>
#include <sstream>
#include <vector>

namespace StringExtend {

std::string Escape(const std::string& s, char escapeCharacter, const std::set< char >& charactersToEscape) {
    std::string output;
    for (size_t i = 0; i < s.length(); ++i) {
        if (charactersToEscape.find(s[i]) != charactersToEscape.end()) {
            output += escapeCharacter;
        }
        output += s[i];
    }
    return output;
}

    std::string Unescape(const std::string& s, char escapeCharacter) {
        std::string output;
        bool escape = false;
        for (size_t i = 0; i < s.length(); ++i) {
            if (!escape && (s[i] == escapeCharacter)) {
                escape = true;
            } else {
                output += s[i];
                escape = false;
            }
        }
        return output;
    }

//    std::string sprintf(const char* format, ...) {
//        va_list args;
//        va_start(args, format);
//        return vsprintf(format, args);
//    }
}