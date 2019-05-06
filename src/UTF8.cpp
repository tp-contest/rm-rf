//
// Created by alex on 06.05.2019.
//

#include <stdint.h>
#include "../includes/UTF8.h"
#include <stddef.h>
#include <vector>


namespace {

    const Utf8::UnicodeCodePoint REPLACEMENT_CHARACTER = 0xFFFD;
    const Utf8::UnicodeCodePoint FIRST_SURROGATE = 0xD800;
    const Utf8::UnicodeCodePoint LAST_SURROGATE = 0xDFFF;
    const Utf8::UnicodeCodePoint LAST_LEGAL_UNICODE_CODE_POINT = 0x10FFFF;
    const std::vector< uint8_t > UTF8_ENCODED_REPLACEMENT_CHARACTER = {0xEF, 0xBF, 0xBD};
    template< typename I > size_t log2n(I integer) {
        size_t answer = 0;
        while (integer > 0) {
            ++answer;
            integer >>= 1;
        }
        return answer;
    }

}

namespace Utf8 {
    struct Utf8::Impl {

        UnicodeCodePoint currentCharacterBeingDecoded = 0;

        size_t numBytesRemainingToDecode = 0;

        size_t bytesTotalToDecodeCurrentCharacter = 0;

        bool isValidEncoding = true;
    };

    Utf8::~Utf8() noexcept = default;
    Utf8::Utf8(): impl_(new Impl) {

    }


    std::vector< uint8_t > Utf8::Encode(const std::vector< UnicodeCodePoint >& codePoints) {
        std::vector< uint8_t > encoding;
        for (auto codePoint: codePoints) {
            const auto numBits = log2n(codePoint);
            if (numBits <= 7) {
                encoding.push_back((UnicodeCodePoint)(codePoint & 0x7F));
            } else if (numBits <= 11) {
                encoding.push_back((UnicodeCodePoint)(((codePoint >> 6) & 0x1F) + 0xC0));
                encoding.push_back((UnicodeCodePoint)((codePoint & 0x3F) + 0x80));
            } else if (numBits <= 16) {
                if ( (codePoint >= FIRST_SURROGATE) && (codePoint <= LAST_SURROGATE)) {
                    (void)encoding.insert(
                            encoding.end(),
                            UTF8_ENCODED_REPLACEMENT_CHARACTER.begin(),
                            UTF8_ENCODED_REPLACEMENT_CHARACTER.end()
                    );
                } else {
                    encoding.push_back((UnicodeCodePoint)(((codePoint >> 12) & 0x0F) + 0xE0));
                    encoding.push_back((UnicodeCodePoint)(((codePoint >> 6) & 0x3F) + 0x80));
                    encoding.push_back((UnicodeCodePoint)((codePoint & 0x3F) + 0x80));
                }
            } else if ((numBits <= 21) && (codePoint <= LAST_LEGAL_UNICODE_CODE_POINT)) {
                encoding.push_back((UnicodeCodePoint)(((codePoint >> 18) & 0x07) + 0xF0));
                encoding.push_back((UnicodeCodePoint)(((codePoint >> 12) & 0x3F) + 0x80));
                encoding.push_back((UnicodeCodePoint)(((codePoint >> 6) & 0x3F) + 0x80));
                encoding.push_back((UnicodeCodePoint)((codePoint & 0x3F) + 0x80));
            } else {
                (void)encoding.insert(
                        encoding.end(),
                        UTF8_ENCODED_REPLACEMENT_CHARACTER.begin(),
                        UTF8_ENCODED_REPLACEMENT_CHARACTER.end()
                );
            }
        }
        return encoding;
    }

    std::vector< UnicodeCodePoint > Utf8::Decode(const std::vector< uint8_t >& encoding) {
        std::vector< UnicodeCodePoint > output;
        for (auto octet: encoding) {
            if (impl_->numBytesRemainingToDecode == 0) {
                if ((octet & 0x80) == 0) {
                    output.push_back(octet);
                } else if ((octet & 0xE0) == 0xC0) {
                    impl_->numBytesRemainingToDecode = 1;
                    impl_->currentCharacterBeingDecoded = (octet & 0x1F);
                } else if ((octet & 0xF0) == 0xE0) {
                    impl_->numBytesRemainingToDecode = 2;
                    impl_->currentCharacterBeingDecoded = (octet & 0x0F);
                } else if ((octet & 0xF8) == 0xF0) {
                    impl_->numBytesRemainingToDecode = 3;
                    impl_->currentCharacterBeingDecoded = (octet & 0x07);
                } else {
                    output.push_back(REPLACEMENT_CHARACTER);
                    impl_->isValidEncoding = false;
                }
                impl_->bytesTotalToDecodeCurrentCharacter = impl_->numBytesRemainingToDecode + 1;
            } else if ((octet & 0xC0) != 0x80) {
                output.push_back(REPLACEMENT_CHARACTER);
                impl_->isValidEncoding = false;
                impl_->numBytesRemainingToDecode = 0;
                const auto nextCodePoints = Decode(std::vector< uint8_t >{ octet });
                output.insert(
                        output.end(),
                        nextCodePoints.begin(),
                        nextCodePoints.end()
                );
            } else {
                impl_->currentCharacterBeingDecoded <<= 6;
                impl_->currentCharacterBeingDecoded += (octet & 0x3F);
                if (--impl_->numBytesRemainingToDecode == 0) {
                    if (
                            (
                                    (impl_->bytesTotalToDecodeCurrentCharacter >= 2)
                                    && (impl_->currentCharacterBeingDecoded < 0x00080)
                            )
                            || (
                                    (impl_->bytesTotalToDecodeCurrentCharacter >= 3)
                                    && (impl_->currentCharacterBeingDecoded < 0x00800)
                            )
                            || (
                                    (impl_->bytesTotalToDecodeCurrentCharacter >= 4)
                                    && (impl_->currentCharacterBeingDecoded < 0x10000)
                            )
                            ) {
                        output.push_back(REPLACEMENT_CHARACTER);
                        impl_->isValidEncoding = false;
                    } else {
                        output.push_back(impl_->currentCharacterBeingDecoded);
                    }
                    impl_->currentCharacterBeingDecoded = 0;
                }
            }
        }
        return output;
    }

    std::vector< UnicodeCodePoint > Utf8::Decode(const std::string& encoding) {
        return Decode(
                std::vector< uint8_t >(
                        encoding.begin(),
                        encoding.end()
                )
        );
    }




}