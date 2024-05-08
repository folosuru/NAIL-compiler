#include "PreservedKeyword.hpp"
#include <memory>

namespace NAIL_cl::Token {
    PreservedKeyword::PreservedKeyword(std::string_view name, std::size_t line, std::int64_t pos, PreservedKeyword::word_type type)
      : Token(name, line, pos) , type(type) {}


    TokenType PreservedKeyword::getType() const {
        return TokenType::Preserved_word;
    }

    Token_ptr PreservedKeyword::create(std::string_view text, std::size_t line, std::int64_t pos) {
        if (text == "for") {
            return std::make_shared<PreservedKeyword>(text, line, pos, PreservedKeyword::word_type::for_t);
        }
        if (text == "var") {
            return std::make_shared<PreservedKeyword>(text, line, pos, PreservedKeyword::word_type::var);
        }
        return nullptr;
    }


} // NAIL_cl::Token