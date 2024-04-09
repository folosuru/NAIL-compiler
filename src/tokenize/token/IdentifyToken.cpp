#include "IdentifyToken.hpp"
#include <iostream>
#include "PreservedKeyword.hpp"

namespace NTSL_cl::Token {
    IdentifyToken::IdentifyToken(std::string_view name, std::size_t line, std::int64_t pos) : Token(name, line, pos) {

    }

    TokenType IdentifyToken::getType() const {
        return TokenType::identify;
    }
    bool is_identify_char(char character) {
        if (
                ('A' <= character && 'Z' >= character) ||
                ('a' <= character && 'z' >= character) ||
            character == '_') {
            return true;
        }
        return false;
    }

    Token_ptr  IdentifyToken::consume(const std::string& str, const std::size_t& line, std::int64_t &pos) {
        std::int64_t start = pos;
        while (is_identify_char(str[pos])) {
            pos++;
        }
        if (start == pos) {
            return nullptr;
        } else {
            std::string_view string = {str.begin() + start , str.begin() + pos };

            if (auto word = PreservedKeyword::create(string, line, start); word != nullptr) {
                return word;
            }

            return std::make_shared<IdentifyToken>(string, line, start);
        }
    }
} // NTSL_cl::Token