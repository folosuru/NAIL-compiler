#ifndef NAIL_CL_EOFTOKEN_HPP
#define NAIL_CL_EOFTOKEN_HPP
#include <string>
#include "Token.hpp"

namespace NAIL_cl::Token {
class EofToken : public Token {
public:
    constexpr static TokenType static_type = TokenType::eof;

    EofToken(const TokenList&);

    ~EofToken() override = default;

    [[nodiscard]]
    TokenType getType() const override;
};
} // Nail_cl::Token

#endif //NAIL_CL_EOFTOKEN_HPP
