#include <tokenize/token/Token.hpp>

namespace NAIL_cl::Token {
    std::string_view Token::getTypeName(TokenType type) {
        switch (type) {
            case TokenType::Preserved_word:
                return "PreservedWord";
            case TokenType::Preserved_symbol:
                return "Symbol";
            case TokenType::identify:
                return "Identify";
            case TokenType::number:
                return "Number";
            case TokenType::text:
                return "Text_Literal";
            case TokenType::eof:
                return "Eof";
        }
    }
}