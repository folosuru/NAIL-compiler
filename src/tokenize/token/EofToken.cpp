#include "EofToken.hpp"

namespace NAIL_cl {
    namespace Token {
        EofToken::EofToken() : Token("", 0, 0) {

        }

        TokenType EofToken::getType() const {
            return TokenType::eof;
        }
    } // Token
} // Nail_cl