//
// Created by alex on 06.05.2019.
//

#ifndef SIMPLEPARSE_UTF8_H
#define SIMPLEPARSE_UTF8_H

#include <memory>
#include <stdint.h>
#include <string>
#include <ostream>
#include <vector>

namespace Utf8 {

    typedef uint32_t UnicodeCodePoint;

    class Utf8 {
        // Lifecycle management
    public:
        ~Utf8() noexcept;

        Utf8(const Utf8 &) = delete;

        Utf8(Utf8 &&) noexcept = delete;

        Utf8 &operator=(const Utf8 &) = delete;

        Utf8 &operator=(Utf8 &&) noexcept = delete;

        // Public methods
    public:

        Utf8();

        static std::vector<uint8_t> Encode(const std::vector<UnicodeCodePoint> &codePoints);

        std::vector<UnicodeCodePoint> Decode(const std::vector<uint8_t> &encoding);

        std::vector<UnicodeCodePoint> Decode(const std::string &encoding);

    private:

        struct Impl;

        std::unique_ptr<Impl> impl_;
    };
}



#endif //SIMPLEPARSE_UTF8_