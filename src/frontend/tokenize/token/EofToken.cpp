#include "EofToken.hpp"
#include <frontend/tokenize/TokenList.hpp>

namespace NAIL_cl {
namespace Token {
EofToken::EofToken(const TokenList& list) : Token("", 0, 0, list) {

}

TokenType EofToken::getType() const {
    return TokenType::eof;
}
} // Token
} // Nail_cl