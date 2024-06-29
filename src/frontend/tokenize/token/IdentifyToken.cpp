#include "IdentifyToken.hpp"

namespace NAIL_cl::Token {
IdentifyToken::IdentifyToken(std::string_view name, std::size_t line, std::int64_t pos, const TokenList& list)
    : Token(name, line, pos, list) {

}

TokenType IdentifyToken::getType() const {
    return TokenType::identify;
}

bool IdentifyToken::is_identify_char(char character) {
    if (
        ('A' <= character && 'Z' >= character) ||
            ('a' <= character && 'z' >= character) ||
            character == '_') {
        return true;
    }
    return false;
}

Token_ptr IdentifyToken::consume(const std::string& str,
                                 const std::size_t& line,
                                 std::int64_t& pos,
                                 const TokenList& list) {
    std::int64_t start = pos;
    while (is_identify_char(str[pos])) {
        pos++;
    }
    if (start == pos) {
        return nullptr;
    } else {
        std::string_view string = {str.begin() + start, str.begin() + pos};
        return std::make_shared<IdentifyToken>(string, line, start, list);
    }
}
} // NAIL_cl::Token