//
// Created by alex on 05.05.2019.
//

#ifndef SIMPLEPARSE_JSONPARSER_H
#define SIMPLEPARSE_JSONPARSER_H

#include <memory>
#include <set>
#include <stack>
#include <map>

namespace JsonParser {


    class JsonParser {
    public:
        JsonParser();
        JsonParser(const JsonParser&) = delete;
        JsonParser(JsonParser&&);
        JsonParser&operator = (const JsonParser&) = delete;
        JsonParser&operator = (JsonParser&&);
        ~JsonParser();

//        std::shared_ptr<JsonParser>operator[](const std::string&  key) const;
//        std::shared_ptr<JsonParser>operator[](char*  key) const;
        bool operator == (const JsonParser& other) const;
//        bool Has(const std::string& key) const;
//        size_t GetSize() const;

        JsonParser(nullptr_t null);
        JsonParser(bool value);
        JsonParser(const std::string& value);

        std::string ToString() const;

        static JsonParser FromString(const std::string& format);

    private:
        struct Impl; //without this string Impl will be declared in a global namespace
        std::unique_ptr<struct Impl> impl_;

    };

}


#endif //SIMPLEPARSE_JSONPARSER_H
