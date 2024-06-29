#include "NumberToken.hpp"

namespace NAIL_cl::Token {
NumberToken::NumberToken(std::string_view name,
                         std::size_t line,
                         std::int64_t pos,
                         const TokenList& list,
                         std::size_t number)
    : Token(name, line, pos, list), value(number) {

}

Token_ptr NumberToken::consume(const std::string& str,
                               const std::size_t& line,
                               std::int64_t& pos,
                               const TokenList& list) {
    if (str[pos] >= '0' && str[pos] <= '9') {
        std::int64_t start = pos;
        std::size_t val = 0;
        std::int64_t value = std::stol(std::string(str.begin() + start, str.end()), &val);
        pos = pos + val;
        return std::make_shared<NumberToken>(
            std::string_view(str.begin() + start, str.begin() + pos),
            line,
            start,
            list,
            value);
    }
    return nullptr;
}

TokenType NumberToken::getType() const {
    return TokenType::number;
}

} // NAIL_cl::Token