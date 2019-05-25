//
// Created by alex on 06.05.2019.
//

#ifndef SIMPLEPARSE_STRINGEXTEND_H
#define SIMPLEPARSE_STRINGEXTEND_H

#include <set>
#include <string>
#include <vector>

namespace StringExtend {

    std::string Escape(const std::string& s, char escapeCharacter, const std::set< char >& charactersToEscape);
    std::string Unescape(const std::string& s, char escapeCharacter);
    std::string sprintf(const char* format, ...);
};


#endif //SIMPLEPARSE_STRINGEXTEND_H
