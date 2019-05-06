//
// Created by alex on 05.05.2019.
//

#include "../includes/JsonParser.h"
#include "../includes/StringExtend.h"
#include "../includes/UTF8.h"

namespace {
    //must be escaped
    const std::set<char> CHAR_TO_ESCAPE{
            '"', '\\', '\b', '\f', '\n', '\r', '\t',
    };
}

namespace JsonParser{
    struct JsonParser::Impl{

        enum class Type{
            Null,  Bolean, Invalid, String, Integer, Object,
        };

        Type type = Type::Invalid;

        union{
            bool BooleanValue;
            std::string* StringValue;
            int IntegerValue;
        };

        //Constructors and destructor

        Impl(const Impl&) = delete;

        Impl(Impl&&) = delete;

        Impl&operator = (const Impl&) = delete;

        Impl&operator = (Impl&&) = delete;
        ~Impl(){
            switch (type) {
                case Impl::Type::String :{
                    delete StringValue;
                }
                    break;

                default:
                    break;
            }

        };

        //Methods

        Impl() = default;
    };

    //default components of class
    JsonParser::~JsonParser() = default;
    JsonParser::JsonParser(JsonParser &&) = default;
    JsonParser &JsonParser::operator=(JsonParser &&) = default;

    bool JsonParser::operator==(const JsonParser &other) const {
        if (impl_->type!=other.impl_->type){
        return false;}
        else switch (impl_->type){
                case Impl::Type::Null:
                    return true;
                case Impl::Type::Bolean:
                    return  impl_->BooleanValue == other.impl_->BooleanValue;
                case Impl::Type::String:
                    return *impl_->StringValue == *other.impl_->StringValue;
                case Impl::Type::Integer:
                    return impl_->IntegerValue == other.impl_->IntegerValue;
                default:
                    return true;
        }
    }

//    std::shared_ptr<JsonParser> JsonParser::operator[](const std::string&  key) const {
//        return (*this)[(size_t)index];
//    }
//
//    std::shared_ptr<JsonParser> JsonParser::operator[](char*  key) const{
//        return (*this)[std::string(key)];
//    }


    //Class's constructors
    JsonParser::JsonParser() : impl_(new Impl){}

        //Null constructor
    JsonParser::JsonParser(nullptr_t null): impl_(new Impl) {
        impl_->type = Impl::Type::Null;
    }

        //Bool constructor
    JsonParser::JsonParser(bool value): impl_(new Impl)
    {
        impl_->type = Impl::Type::Bolean;
        impl_->BooleanValue = value;
    }

        //String constructor
    JsonParser::JsonParser(const std::string& value): impl_(new Impl){
        impl_->type = Impl::Type::String;
        impl_->StringValue = new std::string(value);
    }

        //Integer constructor
//    JsonParser::JsonParser(int value)
//            : impl_(new Impl)
//    {
//        impl_->type = Type::Integer;
//        impl_->integerValue = value;
//    }

    //Writing JSON
    std::string JsonParser::ToString() const {

        switch (impl_->type){
            case Impl::Type::Null:
                return "null";
            case Impl::Type::Bolean:
                return  impl_->BooleanValue ? "true" : "false";
            case Impl::Type::String:
                return ("\""+StringExtend::Escape(*impl_->StringValue, '\\', CHAR_TO_ESCAPE) +"\"");
//            case Impl::Type::Integer: {
//                impl_->encoding = StringExtend::sprintf("%i", impl_->integerValue);
//            } break;
            default:
                return "smthg went wrong";
        }
        return ""; //std::__cxx11::string();
    }

    //Reading JSON
    JsonParser JsonParser::FromString(const std::string &format) {

        if(format == "null") {
            return nullptr;
        } else if (format == "true"){
            return true;
        } else if (format == "false"){
            return false;
        } else if (!format.empty() && (format[0]== '"') && (format[format.length() - 1] == '"')){
            return StringExtend::Unescape(format.substr(1, format.length()-2), '\\');
        }
        else { return JsonParser();}
    }

//    auto JsonParser::GetType() const -> Type {
//        if (impl_ == nullptr) {
//            return Type::Invalid;
//        }
//        return impl_->type;
//    }

//    bool JsonParser::Has(const std::string& key) const {
//        if (GetType() == Type::Object) {
//            return (impl_->objectValue->find(key) != impl_->objectValue->end());
//        } else {
//            return false;
//        }
//    }

 /*   //parsing JSON Object
    std::string ParseValue(const std::string& s, size_t& offset){

        Utf8::Utf8 decoder, encoder;
        std::stack<char > delimiters;
        std::vector<Utf8::UnicodeCodePoint > EncodeValueCodePoints;

        const auto  EncodingCodePoints = decoder.Decode(s.substr(offset));
        if(EncodingCodePoints.empty()){
            offset = std::string::npos;
            return "";
        }

        bool insideString = false;
        for(const auto cp: EncodingCodePoints){

            EncodeValueCodePoints.push_back(cp)

            if(!delimiters.empty() && (cp==delimiters.top())){
                insideString = false;
                delimiters.pop();
                continue;
            }

            if(!insideString){

            if(cp == (Utf8::UnicodeCodePoint)'\"'){
                delimiters.push('\"');
                insideString = true;
            } else if(cp == (Utf8::UnicodeCodePoint)'['){
                delimiters.push(']');
            } else if(cp == (Utf8::UnicodeCodePoint)',' && delimiters.empty()){
                break;
            }
            }

        }
        if(delimiters.empty()){
            auto encodedValue = encoder.Encode(EncodeValueCodePoints);
            offset += encodedValue.size();
            if(EncodeValue.back() == (Utf8::UnicodeCodePoint)','){
                EncodeValue.pop_back();
            }

            return std::string(encodedValue.begin(), encodedValue.end());
        } else{
            offset = std::string::npos;
            return "";
        }
    }

    void ParseJSONObject(const std::string& s){
        std::map<std::string, std::shared_ptr<JsonParser> > newObjectValue;
        size_t  offset = 0;
            while (offset < s.length()){
                const auto EncodedKey = ParseValue(s, offset);
                if(offset == std::string::npos){
                    return;
                }
                const auto Key = std::make_shared<JsonParser>(From)
            }
    }
*/
}